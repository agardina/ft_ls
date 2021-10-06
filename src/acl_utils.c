#include "prototypes.h"

int	file_has_acl_free(t_ls_tree_node *node)
{
	acl_t	a;
	const char	*path;
	char		buffer[__DARWIN_MAXPATHLEN + 1];

	if (S_ISLNK(node->info.st_mode))
	{
		ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
		readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
		path = (const char *)buffer;
	}
	else
		path = (const char *)node->fullpath;
	a = NULL;
	a = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (!a)
		return (0);
	acl_free((void *)a);
	return (1);
}

void	display_acl(t_ls_tree_node *node)
{
	acl_t a;
	char	*text;
	ssize_t	len;

	text = NULL;
	len = 0;
	a = file_has_acl_return_ptr(node);
	if (!a)
		return ;
	text = acl_to_text(a, &len);
	if (text)
		display_acl_text((const char *)text);
	else
		perror("");
	acl_free((void *)a);
	acl_free((void *)text);
}

acl_t file_has_acl_return_ptr(t_ls_tree_node *node)
{
	acl_t	a;
	const char	*path;
	char		buffer[__DARWIN_MAXPATHLEN + 1];

	if (S_ISLNK(node->info.st_mode))
	{
		ft_bzero(buffer, __DARWIN_MAXPATHLEN + 1);
		readlink(node->fullpath, buffer, __DARWIN_MAXPATHLEN);
		path = (const char *)buffer;
	}
	else
		path = (const char *)node->fullpath;

	a = NULL;
	a = acl_get_file(path, ACL_TYPE_EXTENDED);
	return (a);
}

void	display_acl_text(const char *text)
{
	char 	*word;
	char 	*new_line;
	int		word_length;
	int		index;

	new_line = ft_strchr(text, '\n') + 1;
	index = 0;
	while (new_line[0])
	{
		ft_printf("\n");
		ft_printf(" %d: ", index++);
		word = new_line;
		word_length = ft_strchr(word, ':') - word;
		ft_printf("%.*s:", word_length, word);
		word = ft_strchr(word, ':') + 1;
		word = ft_strchr(word, ':') + 1;
		word_length = ft_strchr(word, ':') - word;
		ft_printf("%.*s ", word_length, word);
		word = ft_strchr(word, ':') + 1;
		word = ft_strchr(word, ':') + 1;
		word_length = ft_strchr(word, ':') - word;
		ft_printf("%.*s ", word_length, word);
		word = ft_strchr(word, ':') + 1;
		word_length = ft_strchr(word, '\n') - word;
		ft_printf("%.*s", word_length, word);
		new_line = ft_strchr(word, '\n') + 1;
	}
}
