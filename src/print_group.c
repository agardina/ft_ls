/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:38 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_group(struct stat *info)
{
	struct group *gr;

	gr = getgrgid(info->st_gid);
	ft_printf("%s", gr->gr_name);
}
