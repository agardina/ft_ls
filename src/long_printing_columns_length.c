/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_columns_length.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:27:52 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:27:54 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Return the number of digits of the given integer
**
** \param an integer
**
** \return the number of digits of the given integer
*/
static int	get_number_length(int a)
{
	int	res;

	res = 1;
	while (1)
	{
		a /= 10;
		if (a)
			res++;
		else
			break ;
	}
	return (res);
}

/**
** \brief Get the length of the size (or devices) column
**
** \param node a tree node
** \param data the structure containing the column lengths associated to the
** tree
*/
static void	get_size_or_devices_column_length(t_btree_gen_node *node,
												t_column_lengths *data)
{
	t_ls_tree_node	*content;
	int				major_length;
	int				minor_length;

	content = (t_ls_tree_node *)node->content;
	if (S_ISCHR(content->info.st_mode) || S_ISBLK(content->info.st_mode))
	{
		major_length = get_number_length(content->major);
		data->major = ft_max(data->major, major_length);
		minor_length = get_number_length(content->minor);
		data->minor = ft_max(data->minor, minor_length);
		data->major_minor_total_length = data->major + 2 + data->minor;
		data->max_size_or_device = ft_max(data->max_size_or_device,
				data->major_minor_total_length);
	}
	else
	{
		data->size = ft_max(data->size, ft_strlen(content->size));
		data->max_size_or_device = ft_max(data->max_size_or_device, data->size);
	}
}

/**
** \brief Callback function used by the function \ref get_columns_length
**
** \details The function does an inorder traversal of the tree to carry its
** task out
**
** \param node a tree node
** \param data the structure containing the column lengths associated to the
** tree
*/
static void	get_columns_length_cb(t_ls *ls, t_btree_gen_node *node,
									t_column_lengths *data)
{
	t_ls_tree_node	*content;

	if (!node)
		return ;
	get_columns_length_cb(ls, node->left_child, data);
	content = (t_ls_tree_node *)node->content;
	data->links = ft_max(data->links, get_number_length(content->links));
	data->owner = ft_max(data->owner, (int)ft_strlen(content->owner));
	data->group = ft_max(data->group, (int)ft_strlen(content->group));
	get_size_or_devices_column_length(node, data);
	get_columns_length_cb(ls, node->right_child, data);
}

void	get_columns_length(t_ls *ls, t_btree_gen_node *root,
							t_column_lengths *data)
{
	data->group = -1;
	data->links = -1;
	data->major = -1;
	data->major_minor_total_length = -1;
	data->minor = -1;
	data->owner = -1;
	data->size = -1;
	data->max_size_or_device = -1;
	get_columns_length_cb(ls, root, data);
	data->padding_major = data->max_size_or_device
		- data->major_minor_total_length
		+ data->major;
	data->padding_minor = data->minor;
}
