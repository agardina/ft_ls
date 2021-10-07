/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_compare_content_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:02 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	cmp_operands_size(void *content1, void *content2)
{
	t_ls_tree_node	*node1;
	t_ls_tree_node	*node2;

	node1 = (t_ls_tree_node *)content1;
	node2 = (t_ls_tree_node *)content2;
	if (node1->criteria.size > node2->criteria.size)
		return (-1);
	else if (node1->criteria.size == node2->criteria.size)
		return (cmp_operands_lexico(content1, content2));
	return (1);
}

int	cmp_operands_size_reverse(void *content1, void *content2)
{
	t_ls_tree_node	*node1;
	t_ls_tree_node	*node2;

	node1 = (t_ls_tree_node *)content1;
	node2 = (t_ls_tree_node *)content2;
	if (node1->criteria.size > node2->criteria.size)
		return (1);
	else if (node1->criteria.size == node2->criteria.size)
		return (cmp_operands_lexico_reverse(content1, content2));
	return (-1);
}
