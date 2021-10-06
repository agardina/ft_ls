#include "prototypes.h"

void	display_file_type(struct stat *info)
{
	if (S_ISBLK(info->st_mode))
		ft_printf("b");
	else if (S_ISCHR(info->st_mode))
		ft_printf("c");
	else if (S_ISDIR(info->st_mode))
		ft_printf("d");
	else if (S_ISLNK(info->st_mode))
		ft_printf("l");
	else if (S_ISSOCK(info->st_mode))
		ft_printf("s");
	else if (S_ISFIFO(info->st_mode))
		ft_printf("p");
	else if (S_ISREG(info->st_mode))
		ft_printf("-");
}
