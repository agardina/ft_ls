/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:26:40 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:26:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Move the current char pointer to the next word in an ACL
**
** \details Words are separated by ':'
**
** \param word pointer to the current place in the ACL
*/
static void	acl_skip_next_word(char **word)
{
	*word = ft_strchr(*word, ':') + 1;
}

/**
** \brief Display the user or the group of the current line of an ACL
**
** \param word pointer to the current place in the ACL
*/
static void	acl_display_user_or_group(char **word)
{
	int	word_length;

	word_length = (int)(ft_strchr(*word, ':') - *word);
	ft_printf("%.*s:", word_length, *word);
	acl_skip_next_word(word);
	acl_skip_next_word(word);
	word_length = (int)(ft_strchr(*word, ':') - *word);
	ft_printf("%.*s ", word_length, *word);
}

/**
** \brief Display the permission of the current line of an ACL
**
** \param word pointer to the current place in the ACL
*/
static void	acl_display_permission(char **word)
{
	int	word_length;

	word_length = (int)(ft_strchr(*word, ':') - *word);
	ft_printf("%.*s ", word_length, *word);
	acl_skip_next_word(word);
	word_length = (int)(ft_strchr(*word, '\n') - *word);
	ft_printf("%.*s", word_length, *word);
}

/**
** \brief This function does the actual printing of an ACL
**
** \param text the ACL translated into a NULL terminated character string
*/
static void	print_acl_text(const char *text)
{
	char	*word;
	char	*new_line;
	int		index;

	new_line = ft_strchr(text, '\n') + 1;
	index = 0;
	while (new_line[0])
	{
		ft_printf("\n");
		ft_printf(" %d: ", index++);
		word = new_line;
		acl_display_user_or_group(&word);
		acl_skip_next_word(&word);
		acl_skip_next_word(&word);
		acl_display_permission(&word);
		new_line = ft_strchr(word, '\n') + 1;
	}
}

void	display_acl(t_ls_tree_node *node)
{
	acl_t	a;
	char	*text;
	ssize_t	len;

	text = NULL;
	len = 0;
	a = file_has_acl_return_ptr(node);
	if (!a)
		return ;
	text = acl_to_text(a, &len);
	if (text)
		print_acl_text((const char *)text);
	else
		perror(NULL);
	acl_free((void *)a);
	acl_free((void *)text);
}
