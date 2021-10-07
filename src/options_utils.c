/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:30:07 by agardina          #+#    #+#             */
/*   Updated: 2021/10/07 15:30:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	deactivate_option(t_ls *ls, unsigned int option)
{
	ls->flags &= (~option);
}

int	is_option_activated(t_ls *ls, unsigned int option)
{
	return (ls->flags & option);
}
