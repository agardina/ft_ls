/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:34 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:35 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_file_type(struct stat *info)
{
	printf("Type : ");
	if (S_ISREG(info->st_mode))
		ft_printf("-");
	if (S_ISDIR(info->st_mode))
		ft_printf("d");
}
