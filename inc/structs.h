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
** \brief This structure is used when the long printing option is activated.
** It is used to compute the length of the output's columns.
*/
typedef struct s_column_lengths
{
	int								links;
	int								owner;
	int								group;
	int								size;
	int								major;
	int								minor;
	int								major_minor_total_length;
	int								padding_major;
	int								padding_minor;
	int								max_size_or_device;
}	t_column_lengths;

/**
** \brief Content of the trees used in the ft_ls program
**
** \details The date is expressed with a variable of type long. \n
** The size is expressed with a variable of type long long.
*/

/**
** \brief The main structure used throughout the program
**
** \details It is composed of the flags chosen by the user, the main tree of
** the file operands and the main tree of the directory operands.
*/
typedef struct s_ls
{
	t_btree_gen			main_files_tree;
	t_btree_gen			main_dir_tree;
	t_btree_gen_node	*first_displayed_dir;
	unsigned int		flags;
	int					nb_operands;
	int					err;
	char				padding[4];
}	t_ls;

// A commenter
typedef struct s_create_node
{
	struct stat	*info;
	t_ls		*ls;
	char		*fullpath;
	char		*name;
}	t_create_node;

/**
** \brief Content of the trees used in the program
*/
typedef struct s_ls_tree_node
{
	struct stat			info;
	char				date[14];
	char				padding[2];
	char				mode[12];
	unsigned int		id;
	unsigned long long	links;
	unsigned long long	major;
	unsigned long long	minor;
	char				*name;
	char				*fullpath;
	char				*owner;
	char				*group;
	char				*size;
}	t_ls_tree_node;

#endif
