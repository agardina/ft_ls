#include "prototypes.h"

static void	ls_tree_configure_date_creation_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_USE_TIME_FILE_CREATION))
	{
		ls->files.create_content = &ls_tree_create_content_creation_date;
		ls->dir.create_content = ls->files.create_content;
	}
	else if (is_option_activated(ls, FL_USE_TIME_LAST_ACCESS))
	{
		ls->files.create_content = &ls_tree_create_content_access_date;
		ls->dir.create_content = ls->files.create_content;
	}
	else
	{
		ls->files.create_content = &ls_tree_create_content_modification_date;
		ls->dir.create_content = ls->files.create_content;
	}
}

void	ls_tree_configure_creation_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
	{
		ls->files.create_content = &ls_tree_create_content_size;
		ls->dir.create_content = ls->files.create_content;
	}
	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
		ls_tree_configure_date_creation_function(ls);
	else
	{
		ls->files.create_content = &ls_tree_create_content_lexico;
		ls->dir.create_content = ls->files.create_content;
	}
}
