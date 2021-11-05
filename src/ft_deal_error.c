/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:54:34 by agardina          #+#    #+#             */
/*   Updated: 2021/11/05 17:54:37 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int	ft_deal_error(t_ls *ls, int err_type, const char *arg, int ret)
{
	ls->err = 1;
	if (err_type == LS_ERR_OPENFILE || err_type == LS_ERR_OPENDIR)
		ft_dprintf(2, "ft_ls: %s: %s\n", arg, strerror(errno));
	else if (err_type == LS_ERR_BADOPT)
		ft_dprintf(2, "ft_ls: illegal option -- %c\nusage: "
			"./ft_ls [-@FHRSUadelnrtu1][file ...]\n", *arg);
	return (ret);
}
