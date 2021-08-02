#include "prototypes.h"

/**
** \brief Callback function used by the function \ref display_dir_entries
**
** \param ls the ft_ls structure
** \param node current node whose content will be displayed
** \param column_lengths length of the displayed columns (used when the long printing option is activated)
*/
static void	display_dir_entries_cb(t_ls *ls, t_btree_gen_node *node, t_column_lengths *column_lengths)
{
	// ft_printf("Debug\n");
	if (!node)
		return ;
	// Debug
	// ft_printf("Path: %s\n", path);
	display_dir_entries_cb(ls, node->left_child, column_lengths);
	display_entry(ls, node, column_lengths);
	display_dir_entries_cb(ls, node->right_child, column_lengths);
}

void	display_dir_entries(t_ls *ls, t_btree_gen *dir_entries)
{
	t_column_lengths column_lengths;

	if (is_option_activated(ls, FL_LONG_PRINTING))
		get_columns_length(ls, dir_entries->root, &column_lengths);
	return (display_dir_entries_cb(ls, dir_entries->root, &column_lengths));
}
