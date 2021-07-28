#include "prototypes.h"

void	*ls_tree_create_content_size(void *content)
{
	long long	*size;
	struct stat	info;

	if (lstat((char *)content, &info) == -1)
		return (NULL);
	size = (long long *)malloc(sizeof(long long));
	if (!size)
		return (NULL);
	ft_memcpy(size, &info.st_size, sizeof(long long));
	return (size);
}
