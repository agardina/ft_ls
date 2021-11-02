/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_init_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:40:31 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:40:33 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	ls_tree_init_content(t_ls_tree_node *content)
{
	ft_bzero(content->date, 14);
	content->fullpath = NULL;
	content->group = NULL;
	content->id = 1;
	ft_bzero(content->mode, 12);
	content->name = NULL;
	content->owner = NULL;
	content->size = NULL;
}
