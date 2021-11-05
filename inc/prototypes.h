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
# include <sys/acl.h>
# include <sys/xattr.h>
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
# define FL_DISPLAY_XATTR 0x200
# define FL_DISPLAY_ACL 0x400
# define FL_DISPLAY_DIR_AS_PLAIN_FILES 0x800
# define FL_DISPLAY_CHAR_TO_INDICATE_TYPE 0x1000
# define FL_ONE_ENTRY_PER_LINE 0x2000
# define FL_SYMLNK_CMD_FOLLOWED 0x4000

# define LS_ERR_OPENFILE 1
# define LS_ERR_OPENDIR 2
# define LS_ERR_BADOPT 3
# define LS_ERR_MEM 4
# define LS_ERR_OTHER 5

/**
** \brief Add an option to the ft_ls structure from a flag
**
** \param ls the ft_ls structure
** \param flag the flag associated to the option to add
*/
void	add_option_from_flag(t_ls *ls, unsigned int flag);

/**
** \brief Add an option to the ft_ls structure from a letter parsed in the
** command line
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
** \brief Compare two operands using their date of last access (ascending order)
**
** \details If both operands have the same date, then they will be compared by
** their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand
** is more recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand is
** less recent than that of the second one
*/
int		cmp_operands_atime(void *content1, void *content2);

/**
** \brief Compare two operands using their date of last access
** (descending order)
**
** \details If both operands have the same date, then they will be compared
** by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand
** is less recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand
** is more recent than that of the second one
*/
int		cmp_operands_atime_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their date of birth (ascending order)
**
** \details If both operands have the same date, then they will be compared
** by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand is
** more recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand is
** less recent than that of the second one
*/
int		cmp_operands_btime(void *content1, void *content2);

/**
** \brief Compare two operands using their date of birth (descending order)
**
** \details If both operands have the same date, then they will be compared
** by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand is
** less recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand is
** more recent than that of the second one
*/
int		cmp_operands_btime_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their name (lexicographical order)
**
** \param content1 content of a tree node associated to the first operand
** \param content2 content of a tree node associated to the second operand
**
** \retval -1 if the name of the first operand is less than that of the
** second one
** \retval 0 if the name of the first operand is equal to that of the
** second one
** \retval 1 if the name of the first operand is greater than that of the
** second one
*/
int		cmp_operands_lexico(void *content1, void *content2);

/**
** \brief Compare two operands using their name (reverse lexicographical order)
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand is greater than that of the
** second one
** \retval 0 if the name of the first operand is equal to that of the
** second one
** \retval 1 if the name of the first operand is less than that of the
** second one
*/
int		cmp_operands_lexico_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their date of last modification
** (ascending order)
**
** \details If both operands have the same date, then they will be compared
** by their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand is
** more recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand is
** less recent than that of the second one
*/
int		cmp_operands_mtime(void *content1, void *content2);

/**
** \brief Compare two operands using their date of last modification
** (descending order)
**
** \details If both operands have the same date, then they will be compared by
** their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's date is less recent than that
** of the second one, or if they are equal and the name of the first operand is
** less recent than that of the second one
** \retval 0 if both operands have the same date and name
** \retval 1 if the name of the first operand's date is more recent than that
** of the second one, or if they are equal and the name of the first operand is
** more recent than that of the second one
*/
int		cmp_operands_mtime_reverse(void *content1, void *content2);

/**
** \brief Compare two operands using their size (ascending order)
**
** \details If both operands have the same size, then they will be compared by
** their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's size is less than that of the
** second one, or if they are equal and the name of the first operand is less
** than that of the second one
** \retval 0 if both operands have the same size and name
** \retval 1 if the name of the first operand's size is greater than that of
** the second one, or if they are equal and the name of the first operand is
** greater than that of the second one
*/
int		cmp_operands_size(void *content1, void *content2);

/**
** \brief Compare two operands using their size (descending order)
**
** \details If both operands have the same size, then they will be compared by
** their names
**
** \param content1 content of a tree node associated the first operand
** \param content2 content of a tree node associated the second operand
**
** \retval -1 if the name of the first operand's size is greater than that of
** the second one, or if they are equal and the name of the first operand is
** greater than that of the second one
** \retval 0 if both operands have the same size and name
** \retval 1 if the name of the first operand's size is less than that of the
** second one, or if they are equal and the name of the first operand is less
** than that of the second one
*/
int		cmp_operands_size_reverse(void *content1, void *content2);

/**
** \brief Deactivate an ft_ls option
**
** \param ls the ft_ls structure
** \param option the option to deactivate
*/
void	deactivate_option(t_ls *ls, unsigned int option);

/**
** \brief Deal with the option flags when the -H option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
void	deal_with_big_h_option(t_ls *ls);

/**
** \brief Deal with the option flags when the -S option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
void	deal_with_big_s_option(t_ls *ls);

/**
** \brief Deal with the option flags when the -U option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
void	deal_with_big_u_option(t_ls *ls);

/**
** \brief Deal with the option flags when the -t option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
void	deal_with_little_t_option(t_ls *ls);

/**
** \brief Deal with the option flags when the -u option was found
** in the command line arguments
**
** \param ls the ft_ls structure
*/
void	deal_with_little_u_option(t_ls *ls);

/**
** \brief Display the ACL of a file
**
** \param ls the ft_ls structure
** \param node the content of a tree node related to the file
*/
void	display_acl(t_ls *ls, t_ls_tree_node *node);

/**
** \brief Display a char to indicate the type of a file
**
** \param content the content of the tree node related to the file
*/
void	display_char_to_indicate_type(t_ls_tree_node *content);

/**
** \brief Display the content of a directory
**
** \param ls the ft_ls structure
** \param dir_path the path of the directory
** is going to be displayed, 0 otherwise
** \param is_first_dir 1 if the directory is the first to be displayed
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		display_dir_content(t_ls *ls, const char *dir_path, int is_first_dir);

/**
** \brief Display the content of a directory
**
** \param ls the ft_ls structure
** \param dir_entries a tree containing the directory entries
*/
void	display_dir_entries(t_ls *ls, t_btree_gen *dir_entries);

/**
** \brief Display an entry (file or directory)
*/
void	display_entry(t_ls *ls, t_btree_gen_node *node,
			t_column_lengths *column_lengths);

/**
** \brief Print the name of the file a link links to
**
** \param node the content of the tree node associated to the link
*/
void	display_linked_file(t_ls_tree_node *node);

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
** \brief Display the main tree of files operands
**
** \param ls the ft_ls structure
*/
void	display_main_files_tree(t_ls *ls);

/**
** \brief Display the extended attributes of a file
**
** \param ls the ft_ls structure
** \param node the content of a tree node related to the file
*/
void	display_xattr_list(t_ls *ls, t_ls_tree_node *node);

/**
** \brief Find out if a file has an ACL and free the ACL that was retrieved
**
** \param ls the ft_ls structure
** \param node the content of a tree node related to the file
**
** \retval 0 if the file does not have an ACL
** \retval 1 otherwise
*/
int		file_has_acl_free(t_ls *ls, t_ls_tree_node *node);

/**
** \brief Find out if a file has an ACL and return a pointer to the ACL that
** was retrieved
**
** \param node the content of a tree node related to the file
**
** \return a pointer to the ACL that was retrieved if success, NULL otherwise
*/
acl_t	file_has_acl_return_ptr(t_ls_tree_node *node);

/**
** \brief Find out if a file has extended attributes
**
** \param node a tree node related to the file
**
** \retval 0 if the file does not have extended attributes
** \retval 1 otherwise
*/
int		file_has_xattr(t_ls_tree_node *node);

/**
** \brief Print the ad-hoc error message and set the value of the field err of
** the ft_ls structure to 1
**
** \param ls the ft_ls structure
** \param err_type the type of error (LS_ERR_*)
** \param arg part of the error message
** \param ret the value to return
**
** \return the value of the parameter ret
*/
int		ft_deal_error(t_ls *ls, int err_type, const char *arg, int ret);

/**
** \brief Print the total sum for all the file sizes in a directory (used when
** the long printing option is activated)
**
** \param dir_entries a tree whose nodes correspond to the entries of
** a directory
*/
void	ft_display_total_sum(t_btree_gen *dir_entries);

/**
** \brief When the printing option is activated, this function is used to
** compute the columns length in order to have perfectly aligned columns.
**
** \param ls the ft_ls structure
** \param root the root of a tree
** \param data the structure containing the column lengths associated to the
** tree
*/
void	get_columns_length(t_ls *ls, t_btree_gen_node *root,
			t_column_lengths *data);

/**
** \brief Get the date a file was last modified, last accessed, or created
**
** \param ls the ft_ls structure
** \param content the content of the tree node associated to the file
*/
void	get_date(t_ls *ls, t_ls_tree_node *content);

/**
** \brief Open a directory and put its entries into a tree
**
** \param ls the ft_ls structure
** \param dir_path the path of a directory
** \param dir_entries the tree of directory entries
*/
void	get_dir_entries(t_ls *ls, const char *dir_path,
			t_btree_gen *dir_entries);

/**
** \brief Get the modes of a file
**
** \param ls the ft_ls structure
** \param content the content of the tree node associated to the file
*/
void	get_file_modes(t_ls *ls, t_ls_tree_node *content);

/**
** \brief Get the type of the file
**
** \param content the content of the tree node associated to the file
*/
void	get_file_type(t_ls_tree_node *content);

/**
** \brief Get the fullpath of a directory entry
**
** \param ls the ft_ls structure
** \param dir_path path of directory
** \param entry_name name of the directory entry
**
** \return a newly allocated string if success, NULL otherwise
*/
char	*get_fullpath(t_ls *ls, const char *dir_path, const char *entry_name);

/**
** \brief Get the group that owns the specified file
**
** \param ls the ft_ls structure
** \param content the content of the tree node associated to the file
*/
void	get_group(t_ls *ls, t_ls_tree_node *content);

/**
** \brief Get the elements to print for the given file (in long printing mode)
**
** \param ls the ft_ls structure
** \param content the content of the tree node associated to the file
*/
void	get_long_printing_elements(t_ls *ls, t_ls_tree_node *content);

/**
** \brief Get the number of links a file has
**
** \param content the content of the tree node associated to the file
*/
void	get_nb_links(t_ls_tree_node *content);

/**
** \brief Get the owner of the specified file
**
** \param ls the ft_ls structure
** \param content the content of the tree node associated to the file
*/
void	get_owner(t_ls *ls, t_ls_tree_node *content);

/**
** \brief Get the path of a file or a directory from a tree node
**
** \param ls the ft_ls structure
** \param content the content of a tree node
**
** \return the path of a file or a directory if content is not NULL,
** NULL otherwise
**
** \remark the returned pointer was allocated before this function was called
*/
char	*get_path_from_tree_node(t_ls *ls, void *content);

/**
** \brief Get the size field (when the long printing option is activated)
**
** \details If the file is a character special or block special file, the major
** and minor device numbers for the file are retrieved instead of the size
**
** \param content the content of the tree node associated to the file
*/
void	get_size_or_devices(t_ls_tree_node *content);

/**
** \brief Get the list of the subdirectories contained in the given directory
** and put them into a string vector
**
** \param ls the ft_ls structure
** \param dir_path path to the directory
** \param dir_entries tree of the directory entries
** \param subdirs the string vector to be filled
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		get_subdirs_list(t_ls *ls, const char *dir_path,
			t_btree_gen *dir_entries, t_str_vector **subdirs);

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

/**
** \brief Assign the right node content comparison function to the trees
** contained in the ft_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_comparison_function(t_ls *ls);

/**
** \brief Assign the right node content creation function to the trees
** contained the t_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_creation_function(t_ls *ls);

/**
** \brief Assign the right node content deletion function to the trees
** contained the ft_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_free_function(t_ls *ls);

/**
** \brief Assign the right node content manipulation functions to the trees
** contained the ft_ls structure
**
** \param ls the ft_ls structure
*/
void	ls_tree_configure_functions(t_ls *ls);

/**
** \brief Create the content of a tree node
**
** \param content data used to create the content
**
** \return a pointer to the newly allocated content if success, NULL otherwise
*/
void	*ls_tree_create_content(void *content);

/**
** \brief Free the content of a tree node
**
** \param content the content to free
*/
void	ls_tree_free_content(void **content);

/**
** \brief Initialize the content structure of a tree node associated to a file
**
** \param content the content of the tree node associated to the file
*/
void	ls_tree_init_content(t_ls_tree_node *content);

/**
** \brief Populate the main tree of files and the main tree of directories
** with the operands given to the ft_ls command by the user
**
** \param ls the ft_ls structure
** \param operands the tree of operands
**
** \retval 0 if success
** \retval 1 otherwise
*/
int		populate_trees_with_operands(t_ls *ls, t_btree_str *operands);

/**
** \brief Assign to a tree the same functions as another tree
**
** \param to the tree to assign the functions to
** \param from the tree to get the functions from
*/
void	tree_copy_functions(t_btree_gen *to, t_btree_gen *from);

void	debug_display_tree(t_btree_gen *tree);

void	debug_print_tree(t_btree_gen *tree);

#endif
