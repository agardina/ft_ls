#include "prototypes.h"

void ls_tree_free_content_lexico(void **content)
{
	free(*content);
	*content = NULL;
}

void ls_tree_free_content_size(void **content)
{
	free(*content);
	*content = NULL;
}

void ls_tree_free_content_date(void **content)
{
	t_ls_date_and_size	*s;

	s = (t_ls_date_and_size *)(*content);
	free(s->path);
	free(*content);
	*content = NULL;
}
