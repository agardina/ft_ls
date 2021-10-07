/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_display_nb_links.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:05 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:29:08 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	display_nb_links(struct stat *info, t_column_lengths *column_lengths)
{
	ft_printf("%*d ", column_lengths->links, info->st_nlink);
}
