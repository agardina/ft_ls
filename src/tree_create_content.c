/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_create_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:41:20 by agardina          #+#    #+#             */
/*   Updated: 2021/07/30 10:41:21 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Copy data (fullpath, name, and stat structure) from content to the
** new tree node
**
** \param new the new tree node
** \param content the structure containing the data to copy
*/
static void	copy_data_from_content(t_ls_tree_node **new, void *content)
{
	ft_memcpy(&(*new)->info, ((t_create_node *)content)->info,
		sizeof(struct stat));
	(*new)->fullpath = strdup(((t_create_node *)content)->fullpath);
	if (!(*new)->fullpath)
	{
		free(new);
		*new = NULL;
	}
	(*new)->name = strdup(((t_create_node *)content)->name);
	if (!(*new)->name)
	{
		free((*new)->fullpath);
		free(new);
		*new = NULL;
	}
}

void	*ls_tree_create_content(void *content)
{
	t_ls_tree_node	*new;
	t_ls			*ls;

	new = (t_ls_tree_node *)malloc(sizeof(t_ls_tree_node));
	if (!new)
		return (NULL);
	ls_tree_init_content(new);
	copy_data_from_content(&new, content);
	if (!new)
		return (NULL);
	ls = ((t_create_node *)content)->ls;
	if (is_option_activated(ls, FL_LONG_PRINTING))
		get_long_printing_elements(ls, new);
	return (new);
}
