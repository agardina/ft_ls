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
# include <sys/types.h>
# include <dirent.h>
# include "libft.h"
# include "structs.h"

# define SIX_MONTHS 15552000
# define FL_RECURSIVE_MODE 0x01
# define FL_SORT_BY_SIZE 0x02
# define FL_USE_TIME_FILE_CREATION 0x04
# define FL_DISPLAY_NAMES_DOT 0x08
# define FL_LONG_PRINTING 0x10
# define FL_DISPLAY_UID_GID 0x20
# define FL_REVERSE_ORDER 0x40
# define FL_SORT_BY_TIME_MODIFIED 0x80
# define FL_USE_TIME_LAST_ACCESS 0x100

/* ===== DISPLAYING ===== */

/**
** \brief Display the content of a directory
**
** \param ls the ft_ls structure
** \param dir_path the path of the directory
** \param is_root 1 to indicate the root of the main tree of directories
** is going to be displayed, 0 otherwise
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		display_dir_content(t_ls *ls, const char *dir_path, int is_root);

/**
** \brief Display the main tree of directory operands
**
** \param ls the ft_ls structure
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		display_main_dir_tree(t_ls *ls);

/**
** \brief Display an entry (file or directory)
*/
void	display_entry(t_ls *ls, t_btree_gen_node *node, t_column_lengths *column_lengths);

/**
** \brief Display the main tree of files operands
**
** \param ls the ft_ls structure
*/
void	display_main_files_tree(t_ls *ls);

/**
** \brief Print the date a file was last modified, last accessed, or created
**
** \param ls the ft_ls structure
** \param info a stat structure containing the information regarding the file
*/
void	display_date(t_ls *ls, struct stat *info);

/**
** \brief Print the modes of a file
**
** \param info a stat structure containing the information regarding the file
*/
void	display_file_modes(struct stat *info);

/**
** \brief Print the group that owns the specified file
**
** \param ls the ft_ls structure
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
void	display_group(t_ls *ls, struct stat *info, t_column_lengths *column_lengths);

/**
** \brief Print the name of the file a link links to
**
** \param node the content of the tree node associated to the link
*/
void	display_linked_file(t_ls_tree_node *node);

/**
** \brief Print the name of a file
**
** \param node the content of the tree node associated to the file
*/
void	display_name(t_ls_tree_node *node);

/**
** \brief Print the number of links a file has
**
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
void	display_nb_links(struct stat *info, t_column_lengths *column_lengths);

/**
** \brief Print the owner of the specified file
**
** \param ls the ft_ls structure
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
void	display_owner(t_ls *ls, struct stat *info, t_column_lengths *column_lengths);

/**
** \brief Print the size field (when the long printing option is activated)
**
** \details If the file is a character special or block special file, the major and minor device numbers for the file are displayed in the size field
**
** \param info a stat structure containing the information regarding the file
** \param column_lengths a structure containing the length of the printed columns (used when the long printing option is activated)
*/
void	display_size_or_devices(struct stat *info, t_column_lengths *column_lengths);

/**
** \brief Main display function of ft_ls
**
** \param ls the ft_ls structure
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		ls_display(t_ls *ls);

/**
** \brief Get the entries of the given directory and put them into a tree
**
** \param ls the ft_ls structure
** \param dir_path the path of the currently used directory
** \param dir_entries the tree of directory entries
**
** \retval 1 in case of error
** \retval 0 otherwise
*/
int	get_dir_entries(t_ls *ls, const char *dir_path, t_btree_gen *dir_entries);

/**
** \brief Get the list of the subdirectories contained in the given directory and put them into a string vector
**
** \param dir_path path to the directory
** \param dir_entries tree of the directory entries
** \param subdirs the string vector to be filled
**
** \retval 0 if success
** \retval 1 otherwise
*/
int	get_subdirs_list(const char *dir_path,t_btree_gen *dir_entries, t_str_vector **subdirs);

/**
** \brief Display the content of a directory
**
** \param ls the ft_ls structure
** \param dir_entries a tree containing the directory entries
*/
void	display_dir_entries(t_ls *ls, t_btree_gen *dir_entries);

/* ===== DISPLAY UTILS ===== */

/**
** \brief Get the path of a file or a directory from a tree node
**
** \param ls the ft_ls structure
** \param content the content of a tree node
**
** \return the path of a file or a directory if content is not NULL, NULL otherwise
**
** \remark the returned pointer was allocated before this function was called
*/
char	*get_path_from_tree_node(t_ls *ls, void *content);

/**
** \brief Get the fullpath of a directory entry
**
** \param dir_path path of directory
** \param entry_name name of the directory entry
**
** \return a newly allocated string if success, NULL otherwise
*/
char	*get_fullpath(const char *dir_path, const char *entry_name);

/* ===== OPTIONS ===== */

/**
** \brief Add an option to the ft_ls structure from a letter parsed in the command line
**
** \details
** - The option -S always trumps the options -t, -tu and -tU.
** - If several -u or -U are specified in the command line arguments,
** the last option specified gets the upper hand.
**
** \param ls the ft_ls structure
** \param option the option to add
*/
void	add_option_from_letter(t_ls *ls, char option);

/**
** \brief Add an option to the ft_ls structure from a flag
**
** \param ls the ft_ls structure
** \param flag the flag associated to the option to add
*/
void	add_option_from_flag(t_ls *ls, unsigned int flag);

/**
** \brief Clean the options in order to properly finish the parsing
** of the options
**
** \details To activate the -u or the -U option, the -t or the -l option
** must be activated too.
**
** \param ls the ft_ls structure
*/
void	clean_options(t_ls *ls);

/**
** \brief Deactivate an ft_ls option
**
** \param ls the ft_ls structure
** \param option the option to deactivate
*/
void	deactivate_option(t_ls *ls, unsigned int option);

/**
** \brief Find out if the given ft_ls option is activated
**
** \param ls the ft_ls structure
** \param option the option to check
**
** \retval 1 if the given option is activated
** \retval 0 instead
*/
int		is_option_activated(t_ls *ls, unsigned int option);

/* ===== PARSING ===== */

/**
** \brief Main parsing function
**
** \param ls the ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		ls_parsing(t_ls *ls, int argc, char **argv);

/**
** \brief Parse the operands given by the user in the command line arguments
**
** \param ls the ft_ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
** \param index_parsed the number of command line arguments already parsed
** (by the \ref ls_parsing_options function)
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		ls_parsing_operands(t_ls *ls, int argc, char **argv, int index_parsed);

/**
** \brief Parse the options specified by the user of the ft_ls program
**
** \details Supported options: -R, -S, -U, -a, -l, -n, -r, -t, -u
**
** \param ls the ls structure
** \param argc number of command line arguments + 1
** \param argv array of command line arguments
**
** \return the number of command line arguments that were parsed by
** the function if success
** \return -1 if an unsupported option was found
*/
int		ls_parsing_options(t_ls *ls, int argc, char **argv);

/* ===== CREATION OF TREE NODES CONTENT ===== */

// void	*ls_tree_create_content(t_ls *ls, char *path);

/**
** \brief Create the content of a tree node (when files are sorted by last access date)
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content_access_date(void *content);

/**
** \brief Create the content of a tree node (when files are sorted by creation date)
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content_creation_date(void *content);

/**
** \brief Create the content of a tree node (when files are sorted by lexicographical order)
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content_lexico(void *content);

/**
** \brief Create the content of a tree node (when files are sorted by last modification date)
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content_modification_date(void *content);

/**
** \brief Create the content of a tree node (when files are sorted by size)
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content_size(void *content);

/* ===== FREE TREE NODES CONTENT ===== */

/**
** \brief Free the content of a tree node
**
** \param content the content to free
*/
void	ls_tree_free_content(void **content);

/* ===== OPERANDS COMPARISON =====*/

/**
** \brief Compare two operands using their name (lexicographical order)
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand is less than that of the second one
** \retval 0 if the name of the first operand is equal to that of the second one
** \retval 1 if the name of the first operand is greater than that of the second one
*/
int		compare_operands_lexico(void *content1, void *content2);

/**
** \brief Compare two operands using their name (reverse lexicographical order)
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand is greater than that of the second one
** \retval 0 if the name of the first operand is equal to that of the second one
** \retval 1 if the name of the first operand is less than that of the second one
*/
int		compare_operands_lexico_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their size (ascending order)
**
** \details If both operands have the same size, then they will be compared by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's size is less than that of the second one, or if they are equal and the name of the first operand is less than that of the second one
** \retval 0 if both operands have the same size and name
** \retval 1 if the name of the first operand's size is greater than that of the second one, or if they are equal and the name of the first operand is greater than that of the second one
*/
int		compare_operands_size(void *content1, void *content2);

/**
** \brief Compare two operands using their size (descending order)
**
** \details If both operands have the same size, then they will be compared by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's size is greater than that of the second one, or if they are equal and the name of the first operand is greater than that of the second one
** \retval 0 if both operands have the same size and name
** \retval 1 if the name of the first operand's size is less than that of the second one, or if they are equal and the name of the first operand is less than that of the second one
*/
int		compare_operands_size_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their date (ascending order)
**
** \details If both operands have the same date, then they will be compared by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is more recent than that of the second one, or if they are equal and the name of the first operand is more recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is less recent than that of the second one, or if they are equal and the name of the first operand is less recent than that of the second one
*/
int		compare_operands_time(void *content1, void *content2);

/**
** \brief Compare two operands using their date (descending order)
**
** \details If both operands have the same date, then they will be compared by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is less recent than that of the second one, or if they are equal and the name of the first operand is less recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is more recent than that of the second one, or if they are equal and the name of the first operand is more recent than that of the second one
*/
int		compare_operands_time_reverse(void *content1, void *content2);

/* ===== TREE FUNCTIONS CONFIGURATION ===== */

/**
** \brief Assign the right node content creation function to the trees contained the t_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_creation_function(t_ls *ls);

/**
** \brief Assign the right node content comparison function to the trees contained the t_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_comparison_function(t_ls *ls);

/**
** \brief Assign the right node content deletion function to the trees contained the t_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_free_function(t_ls *ls);

/**
** \brief Assign the right node content manipulation functions to the trees contained the t_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_functions(t_ls *ls);

/* ===== TREE UTILS ===== */

/**
** \brief Assign to a tree the same functions as another tree
**
** \param to the tree to assign the functions to
** \param from the tree to get the functions from
*/
void	tree_copy_functions(t_btree_gen *to, t_btree_gen *from);

/* ===== PRINT TOTAL SUM ===== */

/**
** \brief Print the total sum for all the file sizes in a directory (used when the long printing option is activated)
**
** \param dir_entries a tree whose nodes correspond to the entries of a directory
*/
void	ft_display_total_sum(t_btree_gen *dir_entries);

/* ===== DEBUG ===== */

void	debug_display_tree(t_btree_gen *tree);

/* ===== GET COLUMNS LENGTH ===== */

/**
** \brief When the printing option is activated, this function is used to
** compute the columns length in order to have perfectly aligned columns.
**
** \param ls the ft_ls structure
** \param root the root of a tree
** \param data the structure containing the column lengths associated to the
** tree
*/
void	get_columns_length(t_ls *ls, t_btree_gen_node *root, t_column_lengths *data);

/**
** \brief Initialize the content of a tree node
**
** \param the content of a tree node
*/
void	init_ls_tree_node(t_ls_tree_node *node);

#endif
