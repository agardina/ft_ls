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

void	ls_tree_configure_creation_function(t_ls *ls)
{
	ls->main_files_tree.create_content = &ls_tree_create_content;
	ls->main_dir_tree.create_content = ls->main_files_tree.create_content;
}
