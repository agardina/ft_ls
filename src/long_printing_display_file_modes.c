/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_modes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:30 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Print the permissions granted to those who are not the owner nor part of the group of a file
**
** \param info a stat structure containing the information regarding the file
*/
static void	display_file_modes_o(struct stat *info)
{
	if (info->st_mode & S_IROTH)
		ft_printf("r");
	else
		ft_printf("-");
	if (info->st_mode & S_IWOTH)
		ft_printf("w");
	else
		ft_printf("-");
	if (info->st_mode & S_IXOTH && info->st_mode & S_ISVTX)
		ft_printf("t");
	else if (info->st_mode & S_ISVTX)
		ft_printf("T");
	else if (info->st_mode & S_IXOTH)
		ft_printf("x");
	else
		ft_printf("-");
}

/**
** \brief Print the permissions granted to the group of a file
**
** \param info a stat structure containing the information regarding the file
*/
static void	display_file_modes_g(struct stat *info)
{
	if (info->st_mode & S_IRGRP)
		ft_printf("r");
	else
		ft_printf("-");
	if (info->st_mode & S_IWGRP)
		ft_printf("w");
	else
		ft_printf("-");
	if (info->st_mode & S_IXGRP && info->st_mode & S_ISGID)
		ft_printf("s");
	else if (info->st_mode & S_ISGID)
		ft_printf("S");
	else if (info->st_mode & S_IXGRP)
		ft_printf("x");
	else
		ft_printf("-");
}

/**
** \brief Print the permissions granted to the owner of a file
**
** \param info a stat structure containing the information regarding the file
*/
static void	display_file_modes_u(struct stat *info)
{
	if (info->st_mode & S_IRUSR)
		ft_printf("r");
	else
		ft_printf("-");
	if (info->st_mode & S_IWUSR)
		ft_printf("w");
	else
		ft_printf("-");
	if (info->st_mode & S_IXUSR && info->st_mode & S_ISUID)
		ft_printf("s");
	else if (info->st_mode & S_ISUID)
		ft_printf("S");
	else if (info->st_mode & S_IXUSR)
		ft_printf("x");
	else
		ft_printf("-");
}

/**
** \brief Print the type of the file
**
** \param info a stat structure containing the information regarding the file
*/
static void	display_file_type(struct stat *info)
{
	if (S_ISBLK(info->st_mode))
		ft_printf("b");
	else if (S_ISCHR(info->st_mode))
		ft_printf("c");
	else if (S_ISDIR(info->st_mode))
		ft_printf("d");
	else if (S_ISLNK(info->st_mode))
		ft_printf("l");
	else if (S_ISSOCK(info->st_mode))
		ft_printf("s");
	else if (S_ISFIFO(info->st_mode))
		ft_printf("p");
	else if (S_ISREG(info->st_mode))
		ft_printf("-");
}

void	display_file_modes(struct stat *info)
{
	display_file_type(info);
	display_file_modes_u(info);
	display_file_modes_g(info);
	display_file_modes_o(info);
	ft_printf("  ");
}
