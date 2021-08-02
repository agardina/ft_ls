/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_configure_free_function.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:13 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:13 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

// void	ls_tree_configure_free_function(t_ls *ls)
// {
// 	if (is_option_activated(ls, FL_SORT_BY_SIZE))
// 	{
// 		ls->main_files_tree.free_content = &ls_tree_free_content_size;
// 		ls->main_dir_tree.free_content = ls->main_files_tree.free_content;
// 	}
// 	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
// 	{
// 		ls->main_files_tree.free_content = &ls_tree_free_content_date;
// 		ls->main_dir_tree.free_content = ls->main_files_tree.free_content;
// 	}
// 	else
// 	{
// 		ls->main_files_tree.free_content = &ls_tree_free_content_lexico;
// 		ls->main_dir_tree.free_content = ls->main_files_tree.free_content;
// 	}
// }

void	ls_tree_configure_free_function(t_ls *ls)
{
	ls->main_files_tree.free_content = &ls_tree_free_content;
	ls->main_dir_tree.free_content = ls->main_files_tree.free_content;
}
