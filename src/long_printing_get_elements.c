/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_printing_get_elements.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:37:53 by agardina          #+#    #+#             */
/*   Updated: 2021/11/03 12:37:57 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	get_long_printing_elements(t_ls *ls, t_ls_tree_node *content)
{
	get_file_type(content);
	get_file_modes(content);
	get_nb_links(content);
	get_owner(ls, content);
	get_group(ls, content);
	get_size_or_devices(content);
	get_date(ls, content);
}
