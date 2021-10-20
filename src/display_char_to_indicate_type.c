/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char_to_indicate_type.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:29:46 by agardina          #+#    #+#             */
/*   Updated: 2021/10/20 18:29:48 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Find out if a regular file is executable
**
** \param file_mode the mode of a regular file
**
** \retval 0 if the file is not executable
** \retval 1 otherwise
*/
static int	is_file_executable(mode_t file_mode)
{
	if (file_mode & S_IXUSR)
		return (1);
	else if (file_mode & S_IXGRP)
		return (1);
	else if (file_mode & S_IXOTH)
		return (1);
	return (0);
}

void	display_char_to_indicate_type(t_ls_tree_node *content)
{
	mode_t	file_mode;

	file_mode = content->info.st_mode;
	if (S_ISDIR(file_mode))
		ft_printf("/");
	else if (S_ISREG(file_mode) && is_file_executable(file_mode))
		ft_printf("*");
	else if (S_ISLNK(file_mode))
		ft_printf("@");
	else if (S_ISSOCK(file_mode))
		ft_printf("=");
	else if (S_ISFIFO(file_mode))
		ft_printf("|");
}
