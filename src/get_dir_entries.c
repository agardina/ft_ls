/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_entries.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:05:53 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:05:54 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Add a directory entry to the tree of directory entries
**
** \param ls the ft_ls structure
** \param entry the entry to add to the tree of directory entries
** \param dir_path the path of the currently used directory
** \param dir_entries the tree of directory entries
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	add_dir_entry_to_tree(t_ls *ls, struct dirent *entry,
									const char *dir_path,
									t_btree_gen *dir_entries)
{
	char			*fullpath;
	int				ret;
	t_create_node	data;
	struct stat		info;

	data.fullpath = NULL;
	data.name = entry->d_name;
	fullpath = get_fullpath(ls, dir_path, entry->d_name);
	if (!fullpath)
		return (ft_deal_error(ls, LS_ERR_MEM, NULL, 1));
	data.fullpath = fullpath;
	data.info = &info;
	data.ls = ls;
	if (lstat(fullpath, &info) == -1)
	{
		free(fullpath);
		return (ft_deal_error(ls, LS_ERR_OPENFILE, entry->d_name, 0));
	}
	ret = ft_btree_gen_add_node(dir_entries, (void *)&data);
	free(fullpath);
	return (ret);
}

/**
** \brief Fill the tree of directory entries
**
** \param ls the ft_ls structure
** \param dir a pointer to the DIR structure related to the directory
** \param dir_path the path of the currently used directory
** \param dir_entries the tree of directory entries
*/
static void	fill_tree_of_dir_entries(t_ls *ls, DIR *dir, const char *dir_path,
			t_btree_gen *dir_entries)
{
	struct dirent	*entry;

	entry = readdir(dir);
	errno = 0;
	while (entry)
	{
		if (entry->d_name[0] != '.'
			|| is_option_activated(ls, FL_DISPLAY_NAMES_DOT))
		{
			if (add_dir_entry_to_tree(ls, entry, dir_path, dir_entries))
				break ;
		}
		entry = readdir(dir);
	}
	return ;
}

/**
** \brief From the path of a directory, return its name only
**
** \param str the path of a directory
**
** \return a pointer to the name of the directory
**
** \remark The returned pointer is not allocated, so there is no need to free
** memory after a call to this function
*/
static const char	*ft_transform_name(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (0 <= i && str[i] != '/')
		i--;
	if (i == 0)
		return (str);
	i++;
	return (str + i);
}

void	get_dir_entries(t_ls *ls, const char *dir_path,
						t_btree_gen *dir_entries)
{
	DIR	*dir;

	dir = opendir(dir_path);
	if (!dir)
	{
		ft_deal_error(ls, LS_ERR_OPENDIR, ft_transform_name(dir_path), 1);
		return ;
	}
	fill_tree_of_dir_entries(ls, dir, dir_path, dir_entries);
	closedir(dir);
	return ;
}
