#include "prototypes.h"

void	init_ls_tree_node(t_ls_tree_node *node)
{
	node->fullpath = NULL;
	node->path = NULL;
	node->id = 1;
}
