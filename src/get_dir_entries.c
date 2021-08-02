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
	t_ls_tree_node	content;
	char			*fullpath;
	int				ret;

	ret = 0;
	content.fullpath = NULL;
	while (1)
	{
		entry = readdir(dir);
		if (!entry) // Gestion d'erreur plus fine ?
			break ;
		if (entry->d_name[0] != '.'
			|| is_option_activated(ls, FL_DISPLAY_NAMES_DOT))
		{
			content.path = entry->d_name;
			fullpath = get_fullpath(dir_path, entry->d_name);
			if (!fullpath)
				return (1);
			content.fullpath = fullpath;
			lstat(fullpath, &content.info);
			ret = ft_btree_gen_add_node(dir_entries, (void *)&content);
			free(fullpath);
			if (ret)
				break ;
		}
	}
	return (ret);
}

int	get_dir_entries(t_ls *ls, const char *dir_path, t_btree_gen *dir_entries)
{
	DIR	*dir;
	int	ret;

	ret = 0;
	dir = opendir(dir_path); // Open the directory whose path is given
	if (!dir)
	{
		if (errno == 1)
		{
			ft_dprintf(2, "./ft_ls: %s: Operation not permitted\n", dir_path);
			return (0);
		}
		else if (errno == 13)
		{
			ft_dprintf(2, "./ft_ls: %s: Permission denied\n", dir_path);
			return (0);
		}
		perror(NULL);
		return (1);
	}
	ret = fill_tree_of_dir_entries(ls, dir, dir_path, dir_entries);
	closedir(dir);
	return (ret);
}
