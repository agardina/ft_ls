/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_configure_creation_function.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:10 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:11 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Assign the right node content creation function to the trees contained the t_ls structure (when files are sorted by date)
**
** \param ls the ft_ls structure
*/
static void	ls_tree_configure_date_creation_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
	{
		ls->main_files_tree.create_content = &ls_tree_create_content_creation_date;
		ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
	}
	else if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
	{
		ls->main_files_tree.create_content = &ls_tree_create_content_access_date;
		ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
	}
	else
	{
		ls->main_files_tree.create_content = &ls_tree_create_content_modification_date;
		ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
	}
}

void	ls_tree_configure_creation_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
	{
		ls->main_files_tree.create_content = &ls_tree_create_content_size;
		ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
	}
	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
		ls_tree_configure_date_creation_function(ls);
	else
	{
		ls->main_files_tree.create_content = &ls_tree_create_content_lexico;
		ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
	}
}
