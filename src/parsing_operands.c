/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_operands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:11 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:12 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Allocate memory for the content of the tree node associated to
** the given operand
**
** \param ls the ft_ls structure
** \param path the name of the operand
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	from_operand_to_tree_node(t_ls *ls, char *name)
{
	t_ls_tree_node	content;
	int				ret;

	if (lstat(name, &content.info) == -1)
	{
		if (errno == ENOENT)
			ft_dprintf(2, "ft_ls: %s: No such file or directory\n", name);
		else
			perror(NULL);
		return (0);
	}
	content.path = name;
	content.fullpath = name;
	ret = 0;
	if (S_ISREG(content.info.st_mode) || S_ISLNK(content.info.st_mode))
		ret = ft_btree_gen_add_node(&ls->main_files_tree, (void *)&content);
	else if (S_ISDIR(content.info.st_mode))
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

/**
** \brief Populate the main tree of files and the main tree of directories
** with the operands given to the ft_ls command by the user
**
** \param ls the ft_ls structure
** \param operands the tree of operands
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	populate_trees_with_operands(t_ls *ls, t_btree_str *operands)
{
	return (populate_trees_with_operands_cb(ls, operands->root));
}

int	ls_parsing_operands(t_ls *ls, int argc, char **argv, int index_parsed)
{
	t_btree_str	operands;
	int			ret;

	ft_btree_str_init(&operands);
	if (index_parsed == argc)
	{
		ret = ft_btree_str_add_node(&operands, ".");
		if (ret == -1)
		{
			ft_btree_str_clean(&operands);
			return (1);
		}
	}
	while (index_parsed < argc)
	{
		ret = ft_btree_str_add_node(&operands, argv[index_parsed]);
		if (ret == -1)
		{
			ft_btree_str_clean(&operands);
			return (1);
		}
		index_parsed++;
	}
	if (populate_trees_with_operands(ls, &operands) == -1)
	{
		ft_btree_str_clean(&operands);
		return (1);
	}
	return (0);
}
