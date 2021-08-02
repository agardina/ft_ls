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

struct s_major_minor_devices
{
	int	major;
	int	minor;
	int	total_length;
};

/**
** \brief This structure is used when the long printing option is activated.
** It is used to compute the length of the output's columns.
*/
typedef struct s_column_lengths
{
	int								links;
	int								owner;
	int								group;
	int								size_or_devices;
	struct s_major_minor_devices	major_minor_devices;
}	t_column_lengths;

/**
** \brief This structure is composed of a path to a file and a stat structure
** that will be associated to it.
*/
typedef struct s_path_and_stat
{
	char		*path;
	struct stat	info;
}	t_path_and_stat;

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
	unsigned int	flags;
	t_btree_gen		main_files_tree;
	t_btree_gen		main_dir_tree;
}	t_ls;

/**
** \brief Criteria used to sort the entries to print when the lexicographical
** order is not used. In this case the used criteria is either a size or
** a date.
*/
union u_criteria
{
	long long		size;
	struct timespec	date;
};

/**
** \brief Content of the trees used in the program
*/
typedef struct s_ls_tree_node
{
	char				*path;
	char				*fullpath;
	struct stat			info;
	union u_criteria	criteria;
	unsigned int		id;
}	t_ls_tree_node;

#endif
