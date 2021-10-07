/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_display_link.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:28:54 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:28:56 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_linked_file(t_ls_tree_node *node)
{
	char	buffer[__DARWIN_MAXPATHLEN + 1];

	ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
	readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
	ft_printf(" -> %s", buffer);
}
