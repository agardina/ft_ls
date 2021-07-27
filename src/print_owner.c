/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_owner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:45 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:45 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_owner(struct stat *info)
{
	struct passwd *us;

	us = getpwuid(info->st_uid);
	ft_printf("%s", us->pw_name);
}
