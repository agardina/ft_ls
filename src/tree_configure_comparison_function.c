#include "prototypes.h"

void	ls_tree_configure_comparison_function(t_ls *ls)
{
	if (is_option_activated(ls, FL_SORT_BY_SIZE))
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->files.compare_content = &compare_operands_size_reverse;
		else
			ls->files.compare_content = &compare_operands_size;
		ls->dir.compare_content = ls->files.compare_content;
	}
	else if (is_option_activated(ls, FL_SORT_BY_TIME_MODIFIED))
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->files.compare_content = &compare_operands_time_reverse;
		else
			ls->files.compare_content = &compare_operands_time;
		ls->dir.compare_content = ls->files.compare_content;
	}
	else
	{
		if (is_option_activated(ls, FL_REVERSE_ORDER))
			ls->files.compare_content = &compare_operands_lexico_reverse;
		else
			ls->files.compare_content = &compare_operands_lexico;
		ls->dir.compare_content = ls->files.compare_content;
	}
}
