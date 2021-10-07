/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_main_dir_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:27:21 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:27:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Callback function used by the function \ref display_main_dir_tree
**
** \param ls the ft_ls structure
** \param node current node whose content will be displayed
**
** \retval 0 if success
** \retval 1 otherwise
*/
static int	display_main_dir_tree_cb(t_ls *ls, t_btree_gen_node *node)
{
	char	*dir_path;
	int		ret;

	if (!node)
		return (0);
	if (display_main_dir_tree_cb(ls, node->left_child))
		return (1);
	dir_path = get_path_from_tree_node(ls, node->content);
	ret = display_dir_content(ls, dir_path);
	if (ret)
		return (1);
	if (display_main_dir_tree_cb(ls, node->right_child))
		return (1);
	return (0);
}

static void	get_first_displayed_dir(t_ls *ls)
{
	t_btree_gen_node	*node;

	node = ls->main_dir_tree.root;
	while (node->left_child)
		node = node->left_child;
	ls->first_displayed_dir = node;
}

int	display_main_dir_tree(t_ls *ls)
{
	if (!ls->main_dir_tree.root)
		return (0);
	get_first_displayed_dir(ls);
	return (display_main_dir_tree_cb(ls, ls->main_dir_tree.root));
}
