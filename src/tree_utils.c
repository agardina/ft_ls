#include "prototypes.h"

void	tree_copy_functions(t_btree_gen *to, t_btree_gen *from)
{
	to->compare_content = from->compare_content;
	to->create_content = from->create_content;
	to->free_content = from->free_content;
}
