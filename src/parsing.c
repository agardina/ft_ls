/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:05 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:06 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Main parsing function
**
** \param ls the ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
**
** \retval 0 if success
** \retval -1 otherwise
*/
int	ls_parsing(t_ls *ls, int argc, char **argv)
{
	int ret;

	ret = ls_parsing_options(ls, argc, argv);
	if (-1 < ret)
	{
		clean_options(ls);
		ls_tree_configure_functions(ls);
		ret = ls_parsing_operands(ls, argc, argv, ret);
	}
	else
		return (-1);
	if (ret == -1)
		return (-1);
	return (0);
}
