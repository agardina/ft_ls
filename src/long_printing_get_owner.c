/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_owner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:38:36 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:38:38 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	get_owner(t_ls *ls, t_ls_tree_node *content)
{
	struct passwd	*us;

	us = getpwuid(content->info.st_uid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !us)
		content->owner = ft_itoa(content->info.st_uid);
	else
		content->owner = ft_strdup(us->pw_name);
}
