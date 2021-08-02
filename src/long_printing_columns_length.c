#include "prototypes.h"

/**
** \brief Return the number of digits of the given integer
**
** \param an integer
**
** \return the number of digits of the given integer
*/
static int		get_number_length(int a)
{
	int	res;

	res = 1;
	while (1)
	{
		a /= 10;
		if (a)
			res++;
		else
			break ;
	}
	return (res);
}

/**
** \brief Get the length of the size (or devices) column
**
** \param node a tree node
** \param data the structure containing the column lengths associated to the
** tree
*/
static void	get_size_or_devices_column_length(t_btree_gen_node *node, t_column_lengths *data)
{
	t_ls_tree_node	*content;
	struct stat		*info;
	int				major;
	int				minor;

	content = (t_ls_tree_node *)node->content;
	info = &content->info;
	if (S_ISCHR(info->st_mode) || S_ISBLK(info->st_mode))
	{
		major = get_number_length(major(info->st_rdev));
		if (data->major_minor_devices.major < major)
			data->major_minor_devices.major = major;
		minor = get_number_length(minor(info->st_rdev));
		if (data->major_minor_devices.minor < minor)
			data->major_minor_devices.minor = minor;
		data->major_minor_devices.total_length = data->major_minor_devices.major + 2 + data->major_minor_devices.minor;
		if (data->size_or_devices < data->major_minor_devices.total_length)
			data->size_or_devices = data->major_minor_devices.total_length;
	}
	else
		data->size_or_devices = ft_max(data->size_or_devices, get_number_length(info->st_size));
}

/**
** \brief Callback function used by the function \ref get_columns_length
**
** \details The function does an inorder traversal of the tree to carry its
** task out
**
** \param node a tree node
** \param data the structure containing the column lengths associated to the
** tree
*/
static void	get_columns_length_cb(t_ls *ls, t_btree_gen_node *node, t_column_lengths *data)
{
	t_ls_tree_node	*content;
	struct stat		*info;
	struct passwd	*owner;
	struct group	*gr;

	if (!node)
		return ;
	get_columns_length_cb(ls, node->left_child, data);
	content = (t_ls_tree_node *)node->content;
	info = &content->info;
	data->links = ft_max(data->links, get_number_length(info->st_nlink));
	owner = getpwuid(info->st_uid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !owner)
		data->owner = ft_max(data->owner, get_number_length(info->st_uid));
	else
		data->owner = ft_max(data->owner, (int)ft_strlen(owner->pw_name));
	gr = getgrgid(info->st_gid);
	if (is_option_activated(ls, FL_DISPLAY_UID_GID) || !gr)
		data->group = ft_max(data->group, get_number_length(info->st_gid));
	else
		data->group = ft_max(data->group, (int)ft_strlen(gr->gr_name));
	get_size_or_devices_column_length(node, data);
	get_columns_length_cb(ls, node->right_child, data);
}

void	get_columns_length(t_ls *ls, t_btree_gen_node *root, t_column_lengths *data)
{
	data->group = -1;
	data->links = -1;
	data->major_minor_devices.major = -1;
	data->major_minor_devices.minor = -1;
	data->major_minor_devices.total_length = -1;
	data->owner = -1;
	data->size_or_devices = -1;
	get_columns_length_cb(ls, root, data);
}
