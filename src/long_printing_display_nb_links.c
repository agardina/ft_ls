/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:42 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_nb_links(struct stat *info, t_column_lengths *column_lengths)
{
	ft_printf("%*d ", column_lengths->links, info->st_nlink);
}
