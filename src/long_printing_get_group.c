/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_group.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:38:10 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:38:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	get_group(t_ls *ls, t_ls_tree_node *content)
{
	struct group	*gr;

	gr = getgrgid(content->info.st_gid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !gr)
		content->group = ft_itoa(content->info.st_gid);
	else
		content->group = ft_strdup(gr->gr_name);
}
