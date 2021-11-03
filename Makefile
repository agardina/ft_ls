##### FORMATTING #####

GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

##### COMPILATION #####

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wpadded -g3
NAME = ft_ls

##### LIB #####

LIB_DIR = libft/
LIB_INC = $(LIB_DIR)inc
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_DIR) -lft
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

##### SRC #####

SRC_DIR = src/
SRC_FILES = acl_display.c \
				acl_utils.c \
				debug_print_tree.c \
				display.c \
				display_char_to_indicate_type.c \
				display_dir_content.c \
				display_entries_of_a_dir.c \
				display_entry.c \
				display_main_dir_tree.c \
				display_main_files_tree.c \
				display_utils.c \
				get_dir_entries.c \
				get_subdirs_list.c \
				long_printing_columns_length.c \
				long_printing_display_link.c \
				long_printing_display_total_sum.c \
				long_printing_get_date.c \
				long_printing_get_elements.c \
				long_printing_get_file_modes.c \
				long_printing_get_file_type.c \
				long_printing_get_group.c \
				long_printing_get_nb_links.c \
				long_printing_get_owner.c \
				long_printing_get_size_or_devices.c \
				main.c \
				options_utils.c \
				parsing.c \
				parsing_operands.c \
				parsing_opt.c \
				parsing_opt_add_opt_from_letter.c \
				parsing_opt_clean_opt.c \
				parsing_opt_utils.c \
				parsing_opt_utils_2.c \
				populate_trees_with_operands.c \
				tree_compare_content_atime.c \
				tree_compare_content_btime.c \
				tree_compare_content_lexico.c \
				tree_compare_content_mtime.c \
				tree_compare_content_size.c \
				tree_configure_comparison_function.c \
				tree_configure_creation_function.c \
				tree_configure_free_function.c \
				tree_configure_functions.c \
				tree_create_content.c \
				tree_free_content.c \
				tree_init_content.c \
				tree_utils.c \
				xattr_display.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

##### OBJ #####

OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

##### HDR #####

HDR_DIR = inc/
HDR_FILES = prototypes.h \
				structs.h
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

##### Rules #####

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(LIB) Makefile
	@echo "Object files related to ft_ls created"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	@echo "$(BOLD)$(NAME)$(RESET_FORMAT) [$(GREEN)OK$(RESET_FORMAT)]"

$(LIB): FORCE
	@make -C $(LIB_DIR)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -I$(LIB_INC) -c -o $@ $<
	@echo "Compiled: $*.o [$(GREEN)OK$(RESET_FORMAT)]"
	@echo "$(ERASE_LINE)"

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "Object files related to ft_ls deleted"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re:
	@$(MAKE) fclean
	@echo ""
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
