#include "prototypes.h"

void	*ls_tree_create_content_access_date(void *content)
{
	t_ls_date_and_size	*new;
	struct stat			info;

	if (lstat((char *)content, &info) == -1)
		return (NULL);
	new = (t_ls_date_and_size *)malloc(sizeof(t_ls_date_and_size));
	if (!new)
		return (NULL);
	new->path = strdup((char *)content);
	if (!new->path)
		return (NULL);
	ft_memcpy(&(new->date), &(info.st_atimespec), sizeof(struct timespec));
	return (new);
}

void	*ls_tree_create_content_creation_date(void *content)
{
	t_ls_date_and_size	*new;
	struct stat			info;

	if (lstat((char *)content, &info) == -1)
		return (NULL);
	new = (t_ls_date_and_size *)malloc(sizeof(t_ls_date_and_size));
	if (!new)
		return (NULL);
	new->path = strdup((char *)content);
	if (!new->path)
		return (NULL);
	ft_memcpy(&(new->date), &(info.st_ctimespec), sizeof(struct timespec));
	return (new);
}

void	*ls_tree_create_content_modification_date(void *content)
{
	t_ls_date_and_size	*new;
	struct stat			info;

	if (lstat((char *)content, &info) == -1)
		return (NULL);
	new = (t_ls_date_and_size *)malloc(sizeof(t_ls_date_and_size));
	if (!new)
		return (NULL);
	new->path = strdup((char *)content);
	if (!new->path)
		return (NULL);
	ft_memcpy(&(new->date), &(info.st_mtimespec), sizeof(struct timespec));
	return (new);
}
