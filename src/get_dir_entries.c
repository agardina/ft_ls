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
** \param entry the entry to add to the tree of directory entries
** \param dir_path the path of the currently used directory
** \param dir_entries the tree of directory entries
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	add_dir_entry_to_tree(struct dirent *entry, const char *dir_path,
									t_btree_gen *dir_entries)
{
	char			*fullpath;
	int				ret;
	t_ls_tree_node	content;

	ret = 0;
	content.fullpath = NULL;
	content.path = entry->d_name;
	fullpath = get_fullpath(dir_path, entry->d_name);
	if (!fullpath)
		return (1);
	content.fullpath = fullpath;
	if (stat(fullpath, &content.info) == -1)
	{
		free(fullpath);
		perror("Error with the lstat function");
		return (1);
	}
	ret = ft_btree_gen_add_node(dir_entries, (void *)&content);
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
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	fill_tree_of_dir_entries(t_ls *ls, DIR *dir, const char *dir_path,
			t_btree_gen *dir_entries)
{
	struct dirent	*entry;
	int				ret;

	ret = 0;
	entry = readdir(dir);
	errno = 0;
	while (entry)
	{
		if (entry->d_name[0] != '.'
			|| is_option_activated(ls, FL_DISPLAY_NAMES_DOT))
		{
			if (add_dir_entry_to_tree(entry, dir_path, dir_entries))
				break ;
		}
		entry = readdir(dir);
	}
	if ((!entry && errno) || entry)
	{
		perror("Error while trying to retrieve the next directory entry");
		return (1);
	}
	return (0);
}

int	get_dir_entries(t_ls *ls, const char *dir_path, t_btree_gen *dir_entries)
{
	DIR	*dir;
	int	ret;

	ret = 0;
	dir = opendir(dir_path);
	if (!dir)
	{
		ft_dprintf(2, "./ft_ls: %s: %s\n", dir_path, strerror(errno));
		if (errno == 1 || errno == 13)
			return (0);
		return (1);
	}
	ret = fill_tree_of_dir_entries(ls, dir, dir_path, dir_entries);
	closedir(dir);
	return (ret);
}
