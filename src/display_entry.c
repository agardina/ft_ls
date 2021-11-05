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
static void	display_entry_long_format(t_ls *ls, t_ls_tree_node *content,
				t_column_lengths *column_len)
{
	if (S_ISBLK(content->info.st_mode) || S_ISCHR(content->info.st_mode))
		ft_printf("%s %*llu %-*s  %-*s  %*d, %*d %s %s", content->mode,
			column_len->links, content->links, column_len->owner,
			content->owner, column_len->group, content->group,
			column_len->padding_major, content->major,
			column_len->padding_minor, content->minor, content->date,
			content->name);
	else
		ft_printf("%s %*llu %-*s  %-*s  %*s %s %s", content->mode,
			column_len->links, content->links, column_len->owner,
			content->owner, column_len->group, content->group,
			column_len->max_size_or_device, content->size,
			content->date, content->name);
	if (is_option_activated(ls, FL_DISPLAY_CHAR_TO_INDICATE_TYPE))
		display_char_to_indicate_type(content);
	if (S_ISLNK(content->info.st_mode))
		display_linked_file(content);
	if (is_option_activated(ls, FL_DISPLAY_XATTR))
		display_xattr_list(ls, content);
	if (is_option_activated(ls, FL_DISPLAY_ACL))
		display_acl(ls, content);
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
	ft_printf("%s", content->name);
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
