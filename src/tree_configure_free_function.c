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

void	ls_tree_configure_free_function(t_ls *ls)
{
	ls->main_files_tree.free_content = &ls_tree_free_content;
	ls->main_dir_tree.free_content = ls->main_files_tree.free_content;
}
