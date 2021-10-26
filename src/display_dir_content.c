/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:13:20 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:13:21 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Print the path of a directory
**
** \param ls the ft_ls structure
** \param dir_path path of the directory
** \param is_first_dir 1 if the directory is the first to be displayed
*/
static void	print_dir_path(t_ls *ls, const char *dir_path, int is_first_dir)
{
	t_ls_tree_node	*content;

	content = (t_ls_tree_node *)ls->first_displayed_dir->content;
	if (is_first_dir)
	{
		if (1 < ls->nb_operands)
			ft_printf("%s:\n", dir_path);
	}
	else
		ft_printf("\n%s:\n", dir_path);
}

/**
** \brief Display the content of the given directory's subdirectories
**
** \param ls the ft_ls structure
** \param dir_path path of the directory
** \param dir_entries tree of the given directory's entries
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	display_subdirs_content(t_ls *ls, const char *dir_path,
			t_btree_gen *dir_entries)
{
	t_str_vector	*subdirs;
	unsigned int	i;
	int				ret;

	ret = 0;
	subdirs = str_vector_create();
	if (!subdirs)
		return (1);
	i = 0;
	if (get_subdirs_list(dir_path, dir_entries, &subdirs))
	{
		str_vector_destroy(&subdirs);
		return (1);
	}
	while (i < subdirs->used_size)
	{
		if (display_dir_content(ls, subdirs->tab[i], 0))
		{
			ret = 1;
			break ;
		}
		i++;
	}
	str_vector_destroy(&subdirs);
	return (ret);
}

int	display_dir_content(t_ls *ls, const char *dir_path, int is_first_dir)
{
	t_btree_gen		dir_entries;
	unsigned int	i;
	int				ret;

	print_dir_path(ls, dir_path, is_first_dir);
	i = 0;
	ft_btree_gen_init(&dir_entries);
	tree_copy_functions(&dir_entries, &ls->main_dir_tree);
	if (get_dir_entries(ls, dir_path, &dir_entries))
	{
		ft_btree_gen_clean(&dir_entries);
		return (1);
	}
	// debug_print_tree(&dir_entries);
	if (is_option_activated(ls, FL_LONG_PRINTING) && dir_entries.nb_nodes)
		ft_display_total_sum(&dir_entries);
	display_dir_entries(ls, &dir_entries);
	// Debug
	// ft_printf("Nombre de sous-dossiers : %u\n", subdirs->used_size);
	// str_vector_print(subdirs);
	ret = 0;
	if (is_option_activated(ls, FL_RECURSIVE_MODE))
		ret = display_subdirs_content(ls, dir_path, &dir_entries);
	ft_btree_gen_clean(&dir_entries);
	return (ret);
}
