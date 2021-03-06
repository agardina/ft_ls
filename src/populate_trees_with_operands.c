/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_trees_with_operands.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:46:41 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Find out if a file is a directory
**
** \param info the structure containing the information regarding the file
**
** \retval 0 if the file is not a directory
** \retval 1 otherwise
*/
static int	is_directory(struct stat *info)
{
	if (S_ISDIR(info->st_mode))
		return (1);
	return (0);
}

/**
** \brief Get the stat of a file
**
** \param ls the ft_ls structure
** \param name path of the file
** \param info the structure that will contain the information regarding the file
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	get_file_stat(t_ls *ls, char *name, struct stat *info)
{
	struct stat	linked;

	if (lstat(name, info) == -1)
		return (ft_deal_error(ls, LS_ERR_OPENFILE, name, 1));
	if (S_ISLNK(info->st_mode)
		&& is_option_activated(ls, FL_SYMLNK_CMD_FOLLOWED))
	{
		if (stat(name, &linked) == -1)
			return (0);
		if (S_ISDIR(linked.st_mode))
			ft_memcpy(info, &linked, sizeof(struct stat));
	}
	return (0);
}

/**
** \brief Allocate memory for the content of the tree node associated to
** the given operand
**
** \param ls the ft_ls structure
** \param path the name of the operand
*/
static void	from_operand_to_tree_node(t_ls *ls, char *name)
{
	t_create_node	data;
	struct stat		info;

	if (get_file_stat(ls, name, &info))
		return ;
	data.name = name;
	data.fullpath = name;
	data.info = &info;
	data.ls = ls;
	if (!is_directory(&info) || is_option_activated(ls,
			FL_DISPLAY_DIR_AS_PLAIN_FILES))
		ft_btree_gen_add_node(&ls->main_files_tree, (void *)&data);
	else
		ft_btree_gen_add_node(&ls->main_dir_tree, (void *)&data);
	return ;
}

/**
** \brief Callback function used by the
** function \ref populate_trees_with_operands
**
** \param ls the ft_ls structure
** \param node a node of the tree of operands
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	populate_trees_with_operands_cb(t_ls *ls, t_btree_str_node *node)
{
	if (!node)
		return (0);
	if (populate_trees_with_operands_cb(ls, node->left_child))
		return (1);
	while (node->count)
	{
		from_operand_to_tree_node(ls, node->content);
		node->count--;
	}
	if (populate_trees_with_operands_cb(ls, node->right_child))
		return (1);
	return (0);
}

int	populate_trees_with_operands(t_ls *ls, t_btree_str *operands)
{
	return (populate_trees_with_operands_cb(ls, operands->root));
}
