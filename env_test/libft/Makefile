NAME = libft.a

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = \e[0m
BOLD = \e[1m

SRCS = src/*.c
OBJS = *.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		@$(AR) -r $@ $?
		@printf "\r$(GREEN)$(BOLD)Protocol compiled.$(DEF_COLOR)\n"
		@rm -rf *.o

$(OBJS):
		@$(CC) -c $(CFLAGS) $(SRCS) -I inc

clean: fclean

fclean:
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re