/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:12:35 by agardina          #+#    #+#             */
/*   Updated: 2021/09/23 19:12:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_linked_file(t_ls_tree_node *node)
{
	char	buffer[__DARWIN_MAXPATHLEN + 1];

	ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
	readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
	printf(" -> %s", buffer);
}
