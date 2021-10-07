/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_display_total_sum.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:54 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:29:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Callback function used by the \ref ft_display_total_sum function
**
** \param node a node corresponding to an entry of directory
**
** \return the sum of the sizes of the entry and its childs (if they exist)
*/
static unsigned int	ft_display_total_sum_cb(t_btree_gen_node *node)
{
	unsigned int	total;

	if (!node)
		return (0);
	total = 0;
	total += ft_display_total_sum_cb(node->left_child);
	total += ((t_ls_tree_node *)node->content)->info.st_blocks;
	total += ft_display_total_sum_cb(node->right_child);
	return (total);
}

void	ft_display_total_sum(t_btree_gen *dir_entries)
{
	unsigned int	total;

	total = ft_display_total_sum_cb(dir_entries->root);
	ft_printf("total %u\n", total);
}
