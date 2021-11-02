/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_compare_content_btime.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:39:48 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:39:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	cmp_operands_btime_reverse(void *content1, void *content2)
{
	struct timespec	s1;
	struct timespec	s2;

	s1 = ((t_ls_tree_node *)content1)->info.st_birthtimespec;
	s2 = ((t_ls_tree_node *)content2)->info.st_birthtimespec;
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
	return (cmp_operands_lexico_reverse(content1, content2));
}

int	cmp_operands_btime(void *content1, void *content2)
{
	struct timespec	s1;
	struct timespec	s2;

	s1 = ((t_ls_tree_node *)content1)->info.st_birthtimespec;
	s2 = ((t_ls_tree_node *)content2)->info.st_birthtimespec;
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
	return (cmp_operands_lexico(content1, content2));
}
