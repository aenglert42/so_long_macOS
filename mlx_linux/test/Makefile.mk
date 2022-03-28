
INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I.. -g

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:%.c=%.o)

LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# mac
else
	#Linux and others...
	LFLAGS += -lbsd
endif

#aenglert
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
NC := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "$(GREEN)$(NAME) created$(NC)"

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC			: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		:\n	$(SRC)\n"
	@printf "OBJ		:\n	$(OBJ)\n"

clean:
	@rm -f $(NAME) $(OBJ) *~ core *.core
	@echo "$(RED)$(NAME) deleted$(NC)"

re: clean all
