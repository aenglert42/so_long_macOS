NAME := libft.a
SRC_DIR := ./src/
OBJ_DIR := ./obj/
HEADER_DIR := ./inc/
SRCS :=	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_gnl.c \
		ft_hexlen.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy_c.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_numlen.c \
		ft_putchar_fd.c \
		ft_putcharret_fd.c \
		ft_puteol_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putstrret_fd.c \
		ft_split.c \
		ft_strappend.c \
		ft_strcat_l.c \
		ft_strchr_r.c \
		ft_strchr.c \
		ft_strcmp_n.c \
		ft_strcpy_l.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strrev.c \
		ft_strstr_n.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c
OBJS := $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))
HEADERS := $(HEADER_DIR)*.h
CC := gcc
CFLAGS := -g -Wall -Werror -Wextra
AR := ar
ARFLAGS := rcs
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m
# MAKE += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADERS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "\n$(GREEN)$(NAME) created$(NC)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) ofilemessage
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@echo ".\c"

ofilemessage:
	@echo "compiling $(NAME)-object-files: \c"

clean:
	@rm -rf $(OBJS) *.dSYM
	@echo "$(RED)$(NAME)-object-files deleted$(NC)"
	@echo "$(RED)$(NAME)-dSYM-files deleted$(NC)"

xclean:
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) deleted$(NC)"

fclean: clean xclean

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

.PHONY: clean fclean all re