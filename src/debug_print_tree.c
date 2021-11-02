#include "prototypes.h"

static void	print_function(t_btree_gen_node *node)
{
	t_ls_tree_node	*content;

	if (!node)
		return ;
	content = (t_ls_tree_node *)node->content;
	ft_printf("Noeud: %s\n", content->name);
	if (node->parent)
		ft_printf("Parent: %s\n", content->name);
	else
		ft_printf("Racine\n");
	if (node->left_child)
		ft_printf("Fils gauche: %s\n", content->name);
	else
		ft_printf("Pas de fils gauche\n");
	if (node->right_child)
		ft_printf("Fils droit: %s\n", content->name);
	else
		ft_printf("Pas de fils droit\n");
	ft_printf("\n");
}

static void	debug_print_tree_cb(t_btree_gen_node *node)
{
	if (!node)
		return ;
	debug_print_tree_cb(node->left_child);
	print_function(node);
	debug_print_tree_cb(node->right_child);
}

void	debug_print_tree(t_btree_gen *tree)
{
	if (tree)
		debug_print_tree_cb(tree->root);
	else
		ft_printf("No tree\n");
}
