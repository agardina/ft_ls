/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:40:19 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:40:20 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	ls_display(t_ls *ls)
{
	display_main_files_tree(ls);
	if (ls->main_files_tree.nb_nodes && ls->main_dir_tree.nb_nodes)
		ft_printf("\n");
	return (display_main_dir_tree(ls));
}
