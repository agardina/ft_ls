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

// A commenter
static void	display_xattr_acl_indicator(t_ls_tree_node *node)
{
	const char	*path;
	char		buffer[__DARWIN_MAXPATHLEN + 1];

	if (S_ISLNK(node->info.st_mode))
	{
		ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
		readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
		path = (const char *)buffer;
	}
	else
		path = (const char *)node->fullpath;
	if (file_has_xattr(node) && file_has_acl_free(node))
		ft_printf("@");
	else if (file_has_xattr(node))
		ft_printf("@");
	else if (file_has_acl_free(node))
		ft_printf("+");
	else
		ft_printf(" ");
}

void	display_file_modes(t_ls_tree_node *node)
{
	display_file_modes_u(&node->info);
	display_file_modes_g(&node->info);
	display_file_modes_o(&node->info);
	display_xattr_acl_indicator(node);
	ft_printf(" ");
}
