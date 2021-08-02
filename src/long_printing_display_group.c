/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:38 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_group(t_ls *ls, struct stat *info, t_column_lengths *column_lengths)
{
	struct group	*gr;

	gr = getgrgid(info->st_gid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !gr)
		ft_printf("%-*d  ", column_lengths->group, info->st_gid);
	else
		ft_printf("%-*s  ", column_lengths->group, gr->gr_name);
}
