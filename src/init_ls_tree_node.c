/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ls_tree_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:27:44 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:27:50 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	init_ls_tree_node(t_ls_tree_node *node)
{
	node->fullpath = NULL;
	node->path = NULL;
	node->id = 1;
}
