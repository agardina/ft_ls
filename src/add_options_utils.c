/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_options_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:38:54 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:38:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Deactivate an ft_ls option
**
** \param ls the ft_ls structure
** \param option the option to deactivate
*/
void	deactivate_option(t_ls *ls, unsigned int option)
{
	ls->flags &= (~option);
}

/**
** \brief Find out if the given ft_ls option is activated
**
** \param ls the ft_ls structure
** \param option the option to check
**
** \retval 1 if the given option is activated
** \retval 0 instead
*/
int	is_option_activated(t_ls *ls, unsigned int option)
{
	return (ls->flags & option);
}

/**
** \brief Clean the options in order to properly finish the parsing
** of the options
**
** \param ls the ft_ls structure
*/
void	clean_options(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION)
		&& !is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
		deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
	if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS)
		&& !is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
		deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
}
