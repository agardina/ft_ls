/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xattr_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:30:57 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:30:59 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	file_has_xattr(t_ls_tree_node *node)
{
	ssize_t	xattr_list_length;

	xattr_list_length = listxattr(node->fullpath, NULL, 0, XATTR_NOFOLLOW);
	if (xattr_list_length <= 0)
		return (0);
	return (1);
}

/**
** \brief Store the extended attributes of a file in a buffer
**
** \param ls the ft_ls structure
** \param node the content of a tree node associated to a file
** \param xattr_list_length will hold length of the list of extended
** attributes at the end of the function
**
** \return a pointer to the newly allocated buffer if success, NULL otherwise
*/
static char	*store_xattr_list(t_ls *ls, t_ls_tree_node *node,
								ssize_t *xattr_list_length)
{
	char	*buffer;

	*xattr_list_length = listxattr(node->fullpath, NULL, 0, XATTR_NOFOLLOW);
	buffer = (char *)malloc(sizeof(char) * (*xattr_list_length + 1));
	if (!buffer)
	{
		ft_deal_error(ls, LS_ERR_MEM, NULL, 1);
		return (NULL);
	}
	ft_bzero((void *)buffer, *xattr_list_length + 1);
	listxattr(node->fullpath, buffer, *xattr_list_length + 1, XATTR_NOFOLLOW);
	return (buffer);
}

/**
** \brief This function prints the list of extended attributes of a file
**
** \param ls the ft_ls structure
** \param node the content of a tree node associated to a file
** \param xattr_list the list of extended attributes
** \param xattr_list_length the length of the list of extended attributes
*/
static void	print_xattr_list(t_ls *ls, t_ls_tree_node *node, char *xattr_list,
								ssize_t xattr_list_length)
{
	ssize_t	index;
	ssize_t	value_size;

	index = 0;
	while (index < xattr_list_length)
	{
		ft_printf("\n");
		ft_printf("\t%s       ", xattr_list + index);
		value_size = getxattr(node->fullpath, xattr_list + index, NULL, 0, 0,
				XATTR_NOFOLLOW);
		if (0 <= value_size)
			ft_printf("%lu", value_size);
		else
			ft_deal_error(ls, LS_ERR_OTHER, NULL, 1);
		index += ft_strlen(xattr_list + index) + 1;
	}
}

void	display_xattr_list(t_ls *ls, t_ls_tree_node *node)
{
	ssize_t	xattr_list_length;
	char	*xattr_list;

	if (!file_has_xattr(node))
		return ;
	xattr_list_length = 0;
	xattr_list = store_xattr_list(ls, node, &xattr_list_length);
	if (!xattr_list)
	{
		ft_deal_error(ls, LS_ERR_OTHER, NULL, 1);
		return ;
	}
	print_xattr_list(ls, node, xattr_list, xattr_list_length);
	free(xattr_list);
	xattr_list = NULL;
}
