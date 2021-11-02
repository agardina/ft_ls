/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opt_clean_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:46:43 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:46:45 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Clean the options in order to properly finish the parsing
** of the options
**
** \param ls the ft_ls structure
*/
static void	clean_options_part2(t_ls *ls)
{
	if (!is_option_activated(ls, FL_LONG_PRINTING)
		&& !is_option_activated(ls, FL_DISPLAY_DIR_AS_PLAIN_FILES)
		&& !is_option_activated(ls, FL_DISPLAY_CHAR_TO_INDICATE_TYPE))
		add_option_from_flag(ls, FL_SYMLNK_CMD_FOLLOWED);
}

void	clean_options(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
	{
		if (!is_option_activated(ls, FL_LONG_PRINTING)
			&& !is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
			deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
	}
	if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
	{
		if (!is_option_activated(ls, FL_LONG_PRINTING)
			&& !is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
			deactivate_option(ls, FL_USE_TIME_LAST_ACCESS);
	}
	if (is_option_activated(ls, FL_DISPLAY_UID_GID))
		add_option_from_flag(ls, FL_LONG_PRINTING);
	if (is_option_activated(ls, FL_DISPLAY_XATTR)
		&& !is_option_activated(ls, FL_LONG_PRINTING))
		deactivate_option(ls, FL_DISPLAY_XATTR);
	if (is_option_activated(ls, FL_DISPLAY_ACL)
		&& !is_option_activated(ls, FL_LONG_PRINTING))
		deactivate_option(ls, FL_DISPLAY_ACL);
	if (is_option_activated(ls, FL_DISPLAY_DIR_AS_PLAIN_FILES)
		&& is_option_activated(ls, FL_RECURSIVE_MODE))
		deactivate_option(ls, FL_RECURSIVE_MODE);
	clean_options_part2(ls);
}
