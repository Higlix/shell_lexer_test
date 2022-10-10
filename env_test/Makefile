SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc
LIBFT_DIR = ./libft

SRC = $(wildcard $(SRC_DIR)/*.c)
SRC += $(wildcard $(SRC_DIR)/env/*.c)
SRC += $(wildcard $(SRC_DIR)/printer/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# src/%.c obj/%.o

CFLAGS = -Wall -I $(INC_DIR)
LIB = -lreadline

LIBFT = $(LIBFT_DIR)/libft.a

NAME = hedo

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/env
	mkdir -p $@/printer

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	gcc $(LIB) $(LIBFT) -o $@ $(OBJ)

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

run: all
	@echo "\033[92m \033[3mRunning \033[0m \033[0m"
	@./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all