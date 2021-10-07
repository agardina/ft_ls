/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:07:41 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:07:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

char	*get_path_from_tree_node(t_ls *ls, void *content)
{
	(void)ls;
	if (!content)
		return (NULL);
	return (((t_ls_tree_node *)content)->path);
}

char	*get_fullpath(const char *dir_path, const char *entry_name)
{
	char			*fullpath;
	unsigned int	dir_path_len;
	unsigned int	entry_name_len;

	dir_path_len = ft_strlen(dir_path);
	if (dir_path[dir_path_len - 1] == '/')
		dir_path_len--;
	entry_name_len = ft_strlen(entry_name);
	fullpath = (char *)malloc(sizeof(char)
			* (dir_path_len + 1 + entry_name_len + 1));
	if (!fullpath)
		return (NULL);
	ft_bzero(fullpath, dir_path_len + 1 + entry_name_len + 1);
	ft_strncpy(fullpath, dir_path, dir_path_len);
	ft_strcpy(fullpath + dir_path_len, "/");
	ft_strcpy(fullpath + dir_path_len + 1, entry_name);
	fullpath[dir_path_len + 1 + entry_name_len] = '\0';
	return (fullpath);
}
