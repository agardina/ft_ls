/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_compare_content_time.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:04 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:05 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	compare_operands_time_reverse(void *content1, void *content2)
{
	struct timespec	s1;
	struct timespec	s2;

	s1 = ((t_ls_tree_node *)content1)->criteria.date;
	s2 = ((t_ls_tree_node *)content2)->criteria.date;
	if (s1.tv_sec - s2.tv_sec > 0)
		return (1);
	else if (s1.tv_sec - s2.tv_sec < 0)
		return (-1);
	else
	{
		if (s1.tv_nsec - s2.tv_nsec > 0)
			return (1);
		else if (s1.tv_nsec - s2.tv_nsec < 0)
			return (-1);
	}
	return (compare_operands_lexico_reverse(content1, content2));
}

int	compare_operands_time(void *content1, void *content2)
{
	struct timespec	s1;
	struct timespec	s2;

	s1 = ((t_ls_tree_node *)content1)->criteria.date;
	s2 = ((t_ls_tree_node *)content2)->criteria.date;
	if (s1.tv_sec - s2.tv_sec > 0)
		return (-1);
	else if (s1.tv_sec - s2.tv_sec < 0)
		return (1);
	else
	{
		if (s1.tv_nsec - s2.tv_nsec > 0)
			return (-1);
		else if (s1.tv_nsec - s2.tv_nsec < 0)
			return (1);
	}
	return (compare_operands_lexico(content1, content2));
}
