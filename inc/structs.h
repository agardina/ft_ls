/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:27:37 by agardina          #+#    #+#             */
/*   Updated: 2021/07/27 19:27:42 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H
# include "libft.h"

/**
** \brief Content of the trees used in the ft_ls program
**
** \details The date is expressed with a variable of type long. \n
** The size is expressed with a variable of type long long.
*/
typedef struct s_ls_date_and_size
{
	char			*path;
	struct timespec	date;
} t_ls_date_and_size;

typedef struct s_ls
{
	unsigned int	flags;
	t_btree_gen		files;
	t_btree_gen		dir;
}	t_ls;

#endif
