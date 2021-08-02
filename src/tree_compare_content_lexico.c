/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_compare_content_lexico.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:40:59 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	compare_operands_lexico(void *s1, void *s2)
{
	int				ret;
	t_ls_tree_node 	*content1;
	t_ls_tree_node 	*content2;

	content1 = (t_ls_tree_node *)s1;
	content2 = (t_ls_tree_node *)s2;
	ret = ft_strcmp(content1->path, content2->path);
	if (!ret)
	{
		content1->id++;
		return (-1);
	}
	return (ret);
}

int	compare_operands_lexico_reverse(void *s1, void *s2)
{
	int				ret;
	t_ls_tree_node 	*content1;
	t_ls_tree_node 	*content2;

	content1 = (t_ls_tree_node *)s1;
	content2 = (t_ls_tree_node *)s2;
	ret = ft_strcmp(content1->path, content2->path);
	if (!ret)
	{
		content1->id++;
		return (-1);
	}
	return (-ret);
}
