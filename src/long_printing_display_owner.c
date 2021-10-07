/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_display_owner.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:13 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:29:15 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_owner(t_ls *ls, struct stat *info,
			t_column_lengths *column_lengths)
{
	struct passwd	*us;

	us = getpwuid(info->st_uid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !us)
		ft_printf("%-*d  ", column_lengths->group, info->st_uid);
	else
		ft_printf("%-*s  ", column_lengths->owner, us->pw_name);
}
