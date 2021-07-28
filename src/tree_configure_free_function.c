#include "prototypes.h"

void	ls_tree_configure_free_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
	{
		ls->files.free_content = &ls_tree_free_content_size;
		ls->dir.free_content = ls->files.free_content;
	}
	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
	{
		ls->files.free_content = &ls_tree_free_content_date;
		ls->dir.free_content = ls->files.free_content;
	}
	else
	{
		ls->files.free_content = &ls_tree_free_content_lexico;
		ls->dir.free_content = ls->files.free_content;
	}
}
