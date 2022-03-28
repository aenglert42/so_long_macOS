NAME := so_long
SRC_DIR := ./src/
OBJ_DIR := ./obj/
HEADER_DIR := ./inc/
SRCS :=	enemy.c \
		enemy_movement.c \
		exit.c \
		game.c \
		initialize.c \
		main.c \
		map_check_input.c \
		map_check_setup.c \
		map_display.c \
		map_get_images.c \
		map_put.c \
		map_read.c \
		player.c \
		menu.c \
		random.c \
		timer.c \
		utils.c
OBJS := $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
HEADERS := $(HEADER_DIR)*.h
CC := gcc
CFLAGS := -g -Wall -Wextra -Werror
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m
LIBFT_DIR := ./libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_OBJS := $(LIBFT_DIR)obj/*.o
MLX_DIR := ./mlx/
#MLX_DIR := ./mlx_mac/
#MLX := $(MLX_DIR)libmlx_Linux.a
#MLX := $(MLX_DIR)libmlx.a
MLX := $(MLX_DIR)libmlx.dylib
#MLX_FLAGS := -lXext -lX11 -lm -lz
MLX_FLAGS := -Lmlx -lmlx -framework OpenGL -framework AppKit
DEPS := $(HEADERS) $(LIBFT) $(MLX)
MAKEFLAGS += --no-print-directory

all: link $(NAME)

link:
	@make -C $(LIBFT_DIR)
#	@make -C $(MLX_DIR)

$(NAME): $(OBJ_DIR) $(OBJS) $(DEPS)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $@
	@echo "\n$(GREEN)$(NAME) created$(NC)"
	@echo "$(YELLOW)SUCCESFULLY COMPILED!$(NC)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS) ofilemessage
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -I$(MLX_DIR) -c $< -o $@
	@echo ".\c"

ofilemessage:
	@echo "compiling $(NAME)-object-files: \c"

clean:
	@rm -rf $(OBJS) *.dSYM
	@echo "$(RED)$(NAME)-object-files deleted$(NC)"
	@echo "$(RED)$(NAME)-dSYM-files deleted$(NC)"
	@$(MAKE) clean -C $(LIBFT_DIR)
#	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(NC)"
	@$(MAKE) xclean -C $(LIBFT_DIR)

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

.INTERMEDIATE: ofilemessage

.PHONY: clean fclean all re link