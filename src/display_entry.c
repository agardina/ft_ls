/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:27:15 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:27:17 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Display an entry (in long printing mode)
**
** \param ls the ft_ls structure
** \param node the tree node that contains the content associated to the entry
** \param column_lengths length of the columns that will be printed
*/
static void	display_entry_long_format(t_ls *ls, t_ls_tree_node *node,
				t_column_lengths *column_lengths)
{
	display_file_type(&node->info);
	display_file_modes(node);
	display_nb_links(&node->info, column_lengths);
	display_owner(ls, &node->info, column_lengths);
	display_group(ls, &node->info, column_lengths);
	display_size_or_devices(&node->info, column_lengths);
	display_date(ls, &node->info);
	display_name(node);
	if (is_option_activated(ls, FL_DISPLAY_CHAR_TO_INDICATE_TYPE))
		display_char_to_indicate_type(node);
	if (S_ISLNK(node->info.st_mode))
		display_linked_file(node);
	if (is_option_activated(ls, FL_DISPLAY_XATTR))
		display_xattr_list(node);
	if (is_option_activated(ls, FL_DISPLAY_ACL))
		display_acl(node);
	ft_printf("\n");
}

/**
** \brief Display an entry (normal mode)
**
** \details Only the name of the entry will be displayed
**
** \param ls the ft_ls structure
** \param name name of the entry
*/
static void	display_entry_normal_format(t_ls *ls, t_ls_tree_node *content)
{
	(void)ls;
	ft_printf("%s", content->path);
	if (is_option_activated(ls, FL_DISPLAY_CHAR_TO_INDICATE_TYPE))
		display_char_to_indicate_type(content);
	ft_printf("\n");
}

void	display_entry(t_ls *ls, t_btree_gen_node *node,
			t_column_lengths *column_lengths)
{
	t_ls_tree_node	*content;

	content = (t_ls_tree_node *)node->content;
	if (is_option_activated(ls, FL_LONG_PRINTING))
		display_entry_long_format(ls, content, column_lengths);
	else
		display_entry_normal_format(ls, content);
}
