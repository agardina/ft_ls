/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size_or_devices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:05:20 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:05:24 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Print the major and minor device numbers of a file (when the file is a character special or block special file)
**
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
static void	display_major_minor_devices(struct stat *info,
			t_column_lengths *column_lengths)
{
	int	padding_major;
	int	major_device;
	int	minor_device;

	padding_major = column_lengths->size_or_devices
		- column_lengths->major_minor_devices.total_length;
	major_device = major(info->st_rdev);
	minor_device = minor(info->st_rdev);
	ft_printf("%*d, %*d ", padding_major
		+ column_lengths->major_minor_devices.major, major_device,
		column_lengths->major_minor_devices.minor, minor_device);
}

/**
** \brief Print the size field (when the long printing option is activated)
**
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
static void	display_size(struct stat *info, t_column_lengths *column_lengths)
{
	ft_printf("%*lld ", column_lengths->size_or_devices, info->st_size);
}

void	display_size_or_devices(struct stat *info,
		t_column_lengths *column_lengths)
{
	if (S_ISBLK(info->st_mode) || S_ISCHR(info->st_mode))
		display_major_minor_devices(info, column_lengths);
	else
		display_size(info, column_lengths);
}
