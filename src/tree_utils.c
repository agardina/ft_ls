/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:30:52 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:30:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	tree_copy_functions(t_btree_gen *to, t_btree_gen *from)
{
	to->cmp_content = from->cmp_content;
	to->create_content = from->create_content;
	to->free_content = from->free_content;
}
