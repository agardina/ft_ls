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
** \brief This function adds the current directory as the only operand, when
** no operands were given by the user
**
** \param operands the tree containing the operands
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	ls_parsing_no_operands(t_btree_str *operands)
{
	int	ret;

	ret = ft_btree_str_add_node(operands, ".");
	if (ret == -1)
	{
		ft_btree_str_clean(operands);
		return (1);
	}
	return (0);
}

/**
** \brief Store the operands into a tree
**
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
** \param index_parsed the number of command line arguments already parsed
** (by the \ref ls_parsing_options function)
** \param operands the tree containing the operands
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	store_operands(int argc, char **argv,
			int index_parsed, t_btree_str *operands)
{
	int			ret;

	while (index_parsed < argc)
	{
		ret = ft_btree_str_add_node(operands, argv[index_parsed]);
		if (ret == -1)
		{
			ft_btree_str_clean(operands);
			return (1);
		}
		index_parsed++;
	}
	return (0);
}

int	ls_parsing_operands(t_ls *ls, int argc, char **argv, int index_parsed)
{
	t_btree_str	operands;
	int			ret;

	ls->nb_operands = argc - index_parsed;
	ft_btree_str_init(&operands);
	if (index_parsed == argc)
		ret = ls_parsing_no_operands(&operands);
	else
		ret = store_operands(argc, argv, index_parsed, &operands);
	if (ret)
	{
		ft_btree_str_clean(&operands);
		return (1);
	}
	ret = populate_trees_with_operands(ls, &operands);
	ft_btree_str_clean(&operands);
	return (ret);
}
