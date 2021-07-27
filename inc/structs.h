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

typedef struct s_ls
{
	unsigned int	flags;
	t_btree			files;
	t_btree			dir;
}	t_ls;

#endif
