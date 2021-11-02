/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_size_or_devices.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:39:04 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:39:28 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Print the major and minor device numbers of a file (when the file
** is a character special or block special file)
**
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed
** columns (used when the long printing option is activated)
*/
static void	get_major_minor_devices(t_ls_tree_node *content)
{
	content->major = major(content->info.st_rdev);
	content->minor = minor(content->info.st_rdev);
}

/**
** \brief Print the size field (when the long printing option is activated)
**
** \param node the content of the tree node associated to the file
*/
static void	get_size(t_ls_tree_node *content)
{
	content->size = ft_lltoa(content->info.st_size);
}

void	get_size_or_devices(t_ls_tree_node *content)
{
	if (S_ISBLK(content->info.st_mode) || S_ISCHR(content->info.st_mode))
		get_major_minor_devices(content);
	else
		get_size(content);
}
