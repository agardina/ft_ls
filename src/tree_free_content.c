/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_free_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:25 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:26 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	ls_tree_free_content(void **content)
{
	t_ls_tree_node	*node;

	node = (t_ls_tree_node *)(*content);
	free(node->path);
	free(node->fullpath);
	free(*content);
	*content = NULL;
}
