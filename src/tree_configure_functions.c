/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_configure_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:16 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:17 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	ls_tree_configure_functions(t_ls *ls)
{
	ls_tree_configure_creation_function(ls);
	ls_tree_configure_comparison_function(ls);
	ls_tree_configure_free_function(ls);
}
