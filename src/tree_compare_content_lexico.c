/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_compare_content_lexico.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:40:03 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:40:06 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	cmp_operands_lexico(void *s1, void *s2)
{
	int				ret;
	t_ls_tree_node	*content1;
	t_ls_tree_node	*content2;

	content1 = (t_ls_tree_node *)s1;
	content2 = (t_ls_tree_node *)s2;
	ret = ft_strcmp(content1->name, content2->name);
	if (!ret)
	{
		content1->id++;
		return (-1);
	}
	return (ret);
}

int	cmp_operands_lexico_reverse(void *s1, void *s2)
{
	int				ret;
	t_ls_tree_node	*content1;
	t_ls_tree_node	*content2;

	content1 = (t_ls_tree_node *)s1;
	content2 = (t_ls_tree_node *)s2;
	ret = ft_strcmp(content1->name, content2->name);
	if (!ret)
	{
		content1->id++;
		return (-1);
	}
	return (-ret);
}
