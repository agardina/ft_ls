/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subdirs_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:27:39 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:27:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Add a path to a subdirectory to a string vector
**
** \param ls the ft_ls structure
** \param subdirs he string vector to be filled
** \param dir_path path to the directory
** \param subdir_name name of the subdirectory
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	fill_array_of_subdirs(t_ls *ls, t_str_vector **subdirs,
									const char *dir_path,
									const char *subdir_name)
{
	char	*subdir_path;

	subdir_path = get_fullpath(ls, dir_path, subdir_name);
	if (!subdir_path)
		return (1);
	if (str_vector_append(*subdirs, subdir_path) == 1)
	{
		free(subdir_path);
		return (ft_deal_error(ls, LS_ERR_MEM, NULL, 1));
	}
	free(subdir_path);
	return (0);
}

/**
** \brief Callback function used by the function \ref get_subdirs_list
**
** \param ls the ft_ls structure
** \param dir_path path to the directory
** \param node node of the tree of the directory entries
** \param subdirs the string vector to be filled
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	get_subdirs_list_cb(t_ls *ls, const char *dir_path,
								t_btree_gen_node *node, t_str_vector **subdirs)
{
	t_ls_tree_node	*content;
	int				ret;

	if (!node)
		return (0);
	content = (t_ls_tree_node *)node->content;
	ret = get_subdirs_list_cb(ls, dir_path, node->left_child, subdirs);
	if (ret)
		return (1);
	if (S_ISDIR(content->info.st_mode) && content->name
		&& content->name[0] != '.')
		ret = fill_array_of_subdirs(ls, subdirs, dir_path,
				(const char *)content->name);
	if (ret)
		return (1);
	ret = get_subdirs_list_cb(ls, dir_path, node->right_child, subdirs);
	return (ret);
}

int	get_subdirs_list(t_ls *ls, const char *dir_path, t_btree_gen *dir_entries,
						t_str_vector **subdirs)
{
	return (get_subdirs_list_cb(ls, dir_path, dir_entries->root, subdirs));
}
