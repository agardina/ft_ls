/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:30:28 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:30:30 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Deal with the option flags when the -U option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
static void	deal_with_big_u_option(t_ls *ls)
{
	deactivate_option(ls, FL_USE_TIME_LAST_ACCESS);
	ls->flags |= FL_USE_TIME_FILE_CREATION;
}

/**
** \brief Deal with the option flags when the -u option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
static void	deal_with_little_u_option(t_ls *ls)
{
	deactivate_option(ls, FL_USE_TIME_FILE_CREATION);
	ls->flags |= FL_USE_TIME_LAST_ACCESS;
}

/**
** \brief Deal with the option flags when the -t option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
static void	deal_with_little_t_option(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
		return ;
	ls->flags |= FL_SORT_BY_TIME_MODIFIED;
}

/**
** \brief Deal with the option flags when the -S option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
static void	deal_with_big_s_option(t_ls *ls)
{
	deactivate_option(ls, FL_SORT_BY_TIME_MODIFIED);
	ls->flags |= FL_SORT_BY_SIZE;
}

static void	deal_with_big_h_option(t_ls *ls)
{
	ls->flags |= FL_SYMLNK_CMD_FOLLOWED;
}

/**
** \brief Add an option to the ft_ls structure from a letter parsed in the command line
**
** \details
** - The option -S always trumps the options -t, -tu and -tU.
** - If several -u or -U are specified in the command line arguments,
** the last option specified gets the upper hand.
**
** \param ls the ft_ls structure
** \param option the option to add
*/
static void	add_option_from_letter_part_2(t_ls *ls, char option)
{
	if (option == 'r')
		ls->flags |= FL_REVERSE_ORDER;
	else if (option == 't')
		deal_with_little_t_option(ls);
	else if (option == 'u')
		deal_with_little_u_option(ls);
	else
		return ;
}

void	add_option_from_letter(t_ls *ls, char option)
{
	if (option == '@')
		ls->flags |= FL_DISPLAY_XATTR;
	else if (option == 'F')
		ls->flags |= FL_DISPLAY_CHAR_TO_INDICATE_TYPE;
	else if (option == 'H')
		deal_with_big_h_option(ls);
	else if (option == 'R')
		ls->flags |= FL_RECURSIVE_MODE;
	else if (option == 'S')
		deal_with_big_s_option(ls);
	else if (option == 'U')
		deal_with_big_u_option(ls);
	else if (option == 'a')
		ls->flags |= FL_DISPLAY_NAMES_DOT;
	else if (option == 'd')
		ls->flags |= FL_DISPLAY_DIR_AS_PLAIN_FILES;
	else if (option == 'e')
		ls->flags |= FL_DISPLAY_ACL;
	else if (option == 'l')
		ls->flags |= FL_LONG_PRINTING;
	else if (option == 'n')
		ls->flags |= FL_DISPLAY_UID_GID;
	else
		add_option_from_letter_part_2(ls, option);
}
