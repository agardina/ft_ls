/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_configure_comparison_function.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:07 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:07 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Assign the right time comparison function to the trees contained in
** the t_ls structure
**
** \param ls the ft_ls structure
*/
static void	ls_tree_configure_time_comparison_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->main_files_tree.cmp_content = &cmp_operands_btime_reverse;
		else
			ls->main_files_tree.cmp_content = &cmp_operands_btime;
		ls->main_dir_tree.cmp_content = ls->main_files_tree.cmp_content;
	}
	else if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->main_files_tree.cmp_content = &cmp_operands_atime_reverse;
		else
			ls->main_files_tree.cmp_content = &cmp_operands_atime;
		ls->main_dir_tree.cmp_content = ls->main_files_tree.cmp_content;
	}
	else
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->main_files_tree.cmp_content = &cmp_operands_mtime_reverse;
		else
			ls->main_files_tree.cmp_content = &cmp_operands_mtime;
		ls->main_dir_tree.cmp_content = ls->main_files_tree.cmp_content;
	}
}

void	ls_tree_configure_comparison_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->main_files_tree.cmp_content = &cmp_operands_size_reverse;
		else
			ls->main_files_tree.cmp_content = &cmp_operands_size;
		ls->main_dir_tree.cmp_content = ls->main_files_tree.cmp_content;
	}
	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
		ls_tree_configure_time_comparison_function(ls);
	else
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->main_files_tree.cmp_content = &cmp_operands_lexico_reverse;
		else
			ls->main_files_tree.cmp_content = &cmp_operands_lexico;
		ls->main_dir_tree.cmp_content = ls->main_files_tree.cmp_content;
	}
}
