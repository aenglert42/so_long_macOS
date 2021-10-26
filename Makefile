NAME := so_long
SRC_DIR := ./src/
OBJ_DIR := ./obj/
HEADER_DIR := ./includes/
SRCS :=	exit.c \
		game.c \
		initialize.c \
		main.c \
		map_check_input.c \
		map_check_setup.c \
		map_display.c \
		map_get_images.c \
		map_put.c \
		map_read.c
OBJS := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(wildcard $(SRC_DIR)*.c))
HEADERS := $(HEADER_DIR)*.h
CC := gcc
CFLAGS := -g -Wall -Werror -Wextra -I$(HEADER_DIR)
AR := ar
ARFLAGS := rcs
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m
LIBFT_DIR := ./libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_OBJS := $(LIBFT_DIR)obj/*.o
MLX_DIR := ./mlx/
MLX := $(MLX_DIR)libmlx.a
MLX_FLAGS := -framework OpenGL -framework AppKit
DEPS := $(HEADERS) $(LIBFT) $(MLX)

all: link $(NAME)

link:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@
	@echo "\n$(GREEN)$(NAME) created$(NC)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "$(GREEN)creating: object-files: $(NC)\c"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo ".\c"

clean:
	@rm -f $(OBJ_DIR)*.o
	@echo "$(RED)$(NAME)-object-files deleted$(NC)"
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(NC)"
	@make fclean -C $(LIBFT_DIR)

re: fclean all

peace:
	@echo "\n"
	@echo "     .''.    .',"
	@echo "     |  |   /  /"
	@echo "     |  |  /  /"
	@echo "     |  | /  /"
	@echo "     |  |/  ;-._"
	@echo "     }  \` _/  / ;"
	@echo "     |  /\` ) /  /"
	@echo "     | /  /_/\_/\ "
	@echo "     |/  /      |"
	@echo "     (  ' \ '-  |"
	@echo "      \    \`.  /"
	@echo "       |      |"
	@echo "       |      |\n"

.PHONY: clean fclean all re link