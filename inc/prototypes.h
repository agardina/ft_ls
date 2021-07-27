/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:27:52 by agardina          #+#    #+#             */
/*   Updated: 2021/07/27 19:27:53 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include "libft.h"
# include "structs.h"

# define SIX_MONTHS 15552000
# define FL_RECURSIVE_MODE 0x01
# define FL_SORT_BY_SIZE 0x02
# define FL_USE_TIME_FILE_CREATION 0x04
# define FL_DISPLAY_NAMES_DOT 0x08
# define FL_LONG_FORMAT 0x10
# define FL_DISPLAY_UID_GID 0x20
# define FL_REVERSE_ORDER 0x40
# define FL_SORT_BY_TIME_MODIFIED 0x80
# define FL_USE_TIME_LAST_ACCESS 0x100

void	print_file_modes(struct stat *info);
void	print_file_type(struct stat *info);
void	print_group(struct stat *info);
void	print_owner(struct stat *info);
void	print_nb_links(struct stat *info);
void	print_size(struct stat *info);
void	print_date(struct stat *info);

void	deactivate_option(t_ls *ls, unsigned int option);
int		is_option_activated(t_ls *ls, unsigned int option);

void	add_option(t_ls *ls, char option);
void	clean_options(t_ls *ls);

int		ls_parsing_options(t_ls *ls, int argc, char **argv);

int		ls_parsing(t_ls *ls, int argc, char **argv);

int		ls_display(t_ls *ls);

int		ls_parsing_operands(t_ls *ls, int argc, char **argv, int ret);

#endif
