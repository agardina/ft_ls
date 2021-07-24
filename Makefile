##### FORMATTING #####

GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

##### COMPILATION #####

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
NAME = ft_ls

##### LIB #####

LIB_DIR = libft/
LIB_INC = $(LIB_DIR)inc
LIB_NAME = libft.a
LIB_FLAGS = -L $(LIB_DIR) -lft
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

##### SRC #####

SRC_DIR = src/
SRC_FILES =
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

##### OBJ #####

OBJ_DIR = obj/
LS_OBJ_FILES =
LS_OBJ = $(addprefix $(OBJ_DIR), $(LS_OBJ_FILES))

##### HDR #####

HDR_DIR = inc/
HDR_FILES =
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

##### Rules #####

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LS_OBJ) $(LIB) Makefile
	@echo "Object files related to ft_ls created"
	@$(CC) $(CFLAGS) $(LS_OBJ) $(LIB_FLAGS) -o $(NAME)
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
	@rm -rf $(LS_OBJ)
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
