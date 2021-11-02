/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opt_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:46:46 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:46:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	deal_with_big_u_option(t_ls *ls)
{
	deactivate_option(ls, FL_USE_TIME_LAST_ACCESS);
	ls->flags |= FL_USE_TIME_FILE_CREATION;
}

void	deal_with_little_u_option(t_ls *ls)
{
	deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
	ls->flags |= FL_USE_TIME_LAST_ACCESS;
}

void	deal_with_little_t_option(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
		return ;
	ls->flags |= FL_SORT_BY_TIME_MODIFIED;
}

void	deal_with_big_s_option(t_ls *ls)
{
	deactivate_option(ls, FL_SORT_BY_TIME_MODIFIED);
	ls->flags |= FL_SORT_BY_SIZE;
}

void	deal_with_big_h_option(t_ls *ls)
{
	ls->flags |= FL_SYMLNK_CMD_FOLLOWED;
}
