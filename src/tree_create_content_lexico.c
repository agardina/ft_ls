#include "prototypes.h"

void	*ls_tree_create_content_lexico(void *content)
{
	char	*path;

	path = strdup((char *)content);
	return (path);
}
