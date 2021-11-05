/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_file_modes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:38:00 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:38:01 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Print the permissions granted to those who are not the owner nor
** part of the group of a file
**
** \param content content of a tree node associated to the file
*/
static void	get_file_modes_o(t_ls_tree_node *content)
{
	if (content->info.st_mode & S_IROTH)
		content->mode[7] = 'r';
	else
		content->mode[7] = '-';
	if (content->info.st_mode & S_IWOTH)
		content->mode[8] = 'w';
	else
		content->mode[8] = '-';
	if (content->info.st_mode & S_IXOTH && content->info.st_mode & S_ISVTX)
		content->mode[9] = 't';
	else if (content->info.st_mode & S_ISVTX)
		content->mode[9] = 'T';
	else if (content->info.st_mode & S_IXOTH)
		content->mode[9] = 'x';
	else
		content->mode[9] = '-';
}

/**
** \brief Print the permissions granted to the group of a file
**
** \param content content of a tree node associated to the file
*/
static void	get_file_modes_g(t_ls_tree_node *content)
{
	if (content->info.st_mode & S_IRGRP)
		content->mode[4] = 'r';
	else
		content->mode[4] = '-';
	if (content->info.st_mode & S_IWGRP)
		content->mode[5] = 'w';
	else
		content->mode[5] = '-';
	if (content->info.st_mode & S_IXGRP && content->info.st_mode & S_ISGID)
		content->mode[6] = 's';
	else if (content->info.st_mode & S_ISGID)
		content->mode[6] = 'S';
	else if (content->info.st_mode & S_IXGRP)
		content->mode[6] = 'x';
	else
		content->mode[6] = '-';
}

/**
** \brief Print the permissions granted to the owner of a file
**
** \param content content of a tree node associated to the file
*/
static void	get_file_modes_u(t_ls_tree_node *content)
{
	if (content->info.st_mode & S_IRUSR)
		content->mode[1] = 'r';
	else
		content->mode[1] = '-';
	if (content->info.st_mode & S_IWUSR)
		content->mode[2] = 'w';
	else
		content->mode[2] = '-';
	if (content->info.st_mode & S_IXUSR && content->info.st_mode & S_ISUID)
		content->mode[3] = 's';
	else if (content->info.st_mode & S_ISUID)
		content->mode[3] = 'S';
	else if (content->info.st_mode & S_IXUSR)
		content->mode[3] = 'x';
	else
		content->mode[3] = '-';
}

/**
** \brief Get the char that will be printed after the file's permissions
**
** \details
** - If the file has extended attributes and has ACL, a '@' will be printed
** - If the file only has extended attributes a '@' will be printed
** - If the file only has ACL, a '+' will be printed
** - Otherwise, a ' ' will be printed
**
** \param node
*/
static void	get_xattr_acl_indicator(t_ls *ls, t_ls_tree_node *node)
{
	char		buffer[__DARWIN_MAXPATHLEN + 1];

	if (S_ISLNK(node->info.st_mode))
	{
		ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
		readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
	}
	if (file_has_xattr(node) && file_has_acl_free(ls, node))
		node->mode[10] = '@';
	else if (file_has_xattr(node))
		node->mode[10] = '@';
	else if (file_has_acl_free(ls, node))
		node->mode[10] = '+';
	else
		node->mode[10] = ' ';
}

void	get_file_modes(t_ls *ls, t_ls_tree_node *content)
{
	get_file_modes_u(content);
	get_file_modes_g(content);
	get_file_modes_o(content);
	get_xattr_acl_indicator(ls, content);
}
