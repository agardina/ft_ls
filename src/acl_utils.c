/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:26:49 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:26:51 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	file_has_acl_free(t_ls *ls, t_ls_tree_node *node)
{
	acl_t		a;
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
	a = NULL;
	a = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (!a)
		return (ft_deal_error(ls, LS_ERR_OTHER, NULL, 0));
	acl_free((void *)a);
	return (1);
}

acl_t	file_has_acl_return_ptr(t_ls_tree_node *node)
{
	acl_t		a;
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
	a = NULL;
	a = acl_get_file(path, ACL_TYPE_EXTENDED);
	return (a);
}
