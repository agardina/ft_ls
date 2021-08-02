/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_create_content_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:22 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	*ls_tree_create_content_size(void *content)
{
	t_ls_tree_node	*new;

	new = (t_ls_tree_node *)malloc(sizeof(t_ls_tree_node));
	if (!new)
		return (NULL);
	new->info = ((t_ls_tree_node *)content)->info;
	new->fullpath = strdup(((t_ls_tree_node *)content)->fullpath);
	if (!new->fullpath)
	{
		free(new);
		return (NULL);
	}
	new->path = strdup(((t_ls_tree_node *)content)->path);
	if (!new->path)
	{
		free(new->fullpath);
		free(new);
		return (NULL);
	}
	ft_memcpy(&(new->criteria.size), &(new->info.st_size), sizeof(long long));
	return (new);
}
