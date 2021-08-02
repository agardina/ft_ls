/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_main_files_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:10:28 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:10:29 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Callback function used by the
** function \ref display_main_files_tree
**
** \param ls the ft_ls structure
** \param node current node whose content will be displayed
** \param column_lengths length of the columns that will be printed(when the
** long printing option is activated)
*/
static void	display_main_files_tree_cb(t_ls *ls, t_btree_gen_node *node,
			t_column_lengths *column_lengths)
{
	if (!node)
		return ;
	display_main_files_tree_cb(ls, node->left_child, column_lengths);
	while (node->count)
	{
		display_entry(ls, node, column_lengths);
		node->count--;
	}
	display_main_files_tree_cb(ls, node->right_child, column_lengths);
}

void	display_main_files_tree(t_ls *ls)
{
	t_column_lengths	column_lengths;

	if (!ls->main_files_tree.root)
		return ;
	if (is_option_activated(ls, FL_LONG_PRINTING))
		get_columns_length(ls, ls->main_files_tree.root, &column_lengths);
	display_main_files_tree_cb(ls, ls->main_files_tree.root, &column_lengths);
}
