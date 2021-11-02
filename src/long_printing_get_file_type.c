/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_file_type.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:38:04 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:38:05 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	get_file_type(t_ls_tree_node *content)
{
	if (S_ISBLK(content->info.st_mode))
		content->mode[0] = 'b';
	else if (S_ISCHR(content->info.st_mode))
		content->mode[0] = 'c';
	else if (S_ISDIR(content->info.st_mode))
		content->mode[0] = 'd';
	else if (S_ISLNK(content->info.st_mode))
		content->mode[0] = 'l';
	else if (S_ISSOCK(content->info.st_mode))
		content->mode[0] = 's';
	else if (S_ISFIFO(content->info.st_mode))
		content->mode[0] = 'p';
	else if (S_ISREG(content->info.st_mode))
		content->mode[0] = '-';
}
