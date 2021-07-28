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
# include <sys/errno.h>
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

/*
** Displaying
*/

void	print_date(struct stat *info);
void	print_file_modes(struct stat *info);
void	print_file_type(struct stat *info);
void	print_group(struct stat *info);
void	print_nb_links(struct stat *info);
void	print_owner(struct stat *info);
void	print_size(struct stat *info);
int		ls_display(t_ls *ls);

/*
** Options
*/

void	add_option(t_ls *ls, char option);
void	clean_options(t_ls *ls);
void	deactivate_option(t_ls *ls, unsigned int option);
int		is_option_activated(t_ls *ls, unsigned int option);

/*
** Parsing
*/

int		ls_parsing(t_ls *ls, int argc, char **argv);
int		ls_parsing_operands(t_ls *ls, int argc, char **argv, int index_parsed);
int		ls_parsing_options(t_ls *ls, int argc, char **argv);

/*
** Creation of tree nodes content
*/

void	*ls_tree_create_content(t_ls *ls, char *path);
void	*ls_tree_create_content_access_date(void *content);
void	*ls_tree_create_content_creation_date(void *content);
void	*ls_tree_create_content_lexico(void *content);
void	*ls_tree_create_content_modification_date(void *content);
void	*ls_tree_create_content_size(void *content);


/*
** Free tree nodes content
*/

void	ls_tree_free_content_date(void **content);
void	ls_tree_free_content_lexico(void **content);
void	ls_tree_free_content_size(void **content);

/*
** Operands comparison
*/

int 	compare_operands_lexico(void *s1, void *s2);
int 	compare_operands_lexico_reverse(void *s1, void *s2);
int 	compare_operands_size(void *s1, void *s2);
int 	compare_operands_size_reverse(void *s1, void *s2);
int 	compare_operands_time(void *content1, void *content2);
int 	compare_operands_time_reverse(void *content1, void *content2);

/*
** Tree functions configuration
*/

void	ls_tree_configure_creation_function(t_ls *ls);
void	ls_tree_configure_comparison_function(t_ls *ls);
void	ls_tree_configure_free_function(t_ls *ls);
void	ls_tree_configure_functions(t_ls *ls);

#endif
