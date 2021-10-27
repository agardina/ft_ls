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
** \param content the content of the tree node associated to the file
**
** \retval 0 if the file is not a directory
** \retval 1 otherwise
*/
static int	is_directory(t_ls_tree_node	*content)
{
	if (S_ISDIR(content->info.st_mode))
		return (1);
	return (0);
}

/**
** \brief Allocate memory for the content of the tree node associated to
** the given operand
**
** \param ls the ft_ls structure
** \param path the name of the operand
**
** \retval 0 if success or if error with the lstat function
** \retval 1 in case of memory allocation error
*/
static int	from_operand_to_tree_node(t_ls *ls, char *name)
{
	t_ls_tree_node	content;
	int				ret;

	if (stat(name, &content.info) == -1)
	{
		ft_dprintf(2, "ft_ls: %s: %s\n", name, strerror(errno));
		return (0);
	}
	content.path = name;
	content.fullpath = name;
	ret = 0;
	if (!is_directory(&content) || is_option_activated(ls,
			FL_DISPLAY_DIR_AS_PLAIN_FILES))
		ret = ft_btree_gen_add_node(&ls->main_files_tree, (void *)&content);
	else
		ret = ft_btree_gen_add_node(&ls->main_dir_tree, (void *)&content);
	if (ret)
		return (1);
	return (0);
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
		if (from_operand_to_tree_node(ls, node->content))
			return (1);
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
