#include "prototypes.h"

void	ls_tree_configure_functions(t_ls *ls)
{
	ls_tree_configure_creation_function(ls);
	ls_tree_configure_comparison_function(ls);
	ls_tree_configure_free_function(ls);
}
