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

static void	print_file_modes_o(struct stat *info)
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

static void	print_file_modes_g(struct stat *info)
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

static void	print_file_modes_u(struct stat *info)
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

void	print_file_modes(struct stat *info)
{
	print_file_modes_u(info);
	print_file_modes_g(info);
	print_file_modes_o(info);
}
