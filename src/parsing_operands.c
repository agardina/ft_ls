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

static int from_operand_to_tree_node(t_ls *ls, char *path)
{
	struct stat	info;

	if (lstat(path, &info) == -1)
	{
		if (errno == ENOENT)
			ft_printf("ft_ls: %s: No such file or directory\n", path);
		else
			perror(NULL);
		return (-1);
	}
	if (S_ISREG(info.st_mode)|| S_ISLNK(info.st_mode))
		ft_btree_gen_add_node(&ls->files, (void *)path);
	else if (S_ISDIR(info.st_mode))
		ft_btree_gen_add_node(&ls->dir, (void *)path);
	return (0);
}

static int populate_trees_with_operands_cb(t_ls *ls, t_btree_str_node *node)
{
	int	ret[3];

	if (!node)
		return (0);
	ret[0] = populate_trees_with_operands_cb(ls, node->left_child);
	ret[1] = from_operand_to_tree_node(ls, node->content);
	ret[2] = populate_trees_with_operands_cb(ls, node->right_child);
	if (ret[0] == -1 || ret[1] == -1 || ret[2] == -1)
		return (-1);
	return (0);
}


static int populate_trees_with_operands(t_ls *ls, t_btree_str *operands)
{
	return (populate_trees_with_operands_cb(ls, operands->root));
}

/**
** \brief Parse the operands given by the user in the command line arguments
**
** \param ls the ft_ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
** \param index_parsed the number of command line arguments already parsed
** (by the \ref ls_parsing_options function)
**
** \retval 0 if success
** \retval -1 otherwise
*/
int	ls_parsing_operands(t_ls *ls, int argc, char **argv, int index_parsed)
{
	t_btree_str	operands;
	int			ret;

	ft_btree_str_init(&operands);
	if (index_parsed == argc)
	{
		from_operand_to_tree_node(ls, ".");
		return (0);
	}
	while (index_parsed < argc)
	{
		ret = ft_btree_str_add_node(&operands, argv[index_parsed]);
		if (ret == -1)
		{
			ft_btree_str_clean(&operands);
			return (-1);
		}
		index_parsed++;
	}
	if (populate_trees_with_operands(ls, &operands) == -1)
	{
		ft_btree_str_clean(&operands);
		return (-1);
	}
	return (0);
}
