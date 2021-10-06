#include "prototypes.h"

int		file_has_xattr(t_ls_tree_node *node)
{
	ssize_t	xattr_list_length;

	xattr_list_length = listxattr(node->fullpath, NULL, 0, XATTR_NOFOLLOW);
	if (xattr_list_length <= 0)
		return (0);
	return (1);
}

// Remplacer le buffer par un vecteur

void	display_xattr_list(t_ls_tree_node *node)
{
	ssize_t	xattr_list_length;
	ssize_t	value_size;
	ssize_t	index;
	char	buffer[10000];

	if (!file_has_xattr(node))
		return ;
	xattr_list_length = listxattr(node->fullpath, buffer, 10000, XATTR_NOFOLLOW);
	index = 0;
	while (index < xattr_list_length)
	{
		ft_printf("\n");
		ft_printf("\t%s       ", buffer + index);
		value_size = getxattr(node->fullpath, buffer + index, NULL, 10000, 0, 0);
		ft_printf("%lu", value_size);
		index += ft_strlen(buffer + index) + 1;
	}
}
