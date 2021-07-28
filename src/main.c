/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:39:00 by agardina          #+#    #+#             */
/*   Updated: 2021/07/28 11:39:02 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/**
** \brief Clean the ft_ls structure before exiting the program
**
** \param ls the ft_ls structure to clean
*/
static void	clean_ls_structure(t_ls *ls)
{
	ft_btree_gen_clean(&ls->dir);
	ft_btree_gen_clean(&ls->files);
}

/**
** \brief Initialize the ft_ls structure
**
** \param ls the ft_ls structure to initialize
*/
static void	init_ls_structure(t_ls *ls)
{
	ls->flags = 0;
	ft_btree_gen_init(&ls->dir);
	ft_btree_gen_init(&ls->files);
}

/**
** \brief The main function of the ft_ls program
**
** \param argc the number of command line arguments + 1
** \param argv the array of command line arguments
**
** \return 0 if everything went well
** \return 1 otherwise
*/
int main(int argc, char **argv)
{
	t_ls	ls;
	int		ret;

	init_ls_structure(&ls);
	ret = ls_parsing(&ls, argc, argv);
	if (-1 < ret)
		ls_display(&ls);
	clean_ls_structure(&ls);
	if (ret == -1)
		return (1);
	return (0);
}
