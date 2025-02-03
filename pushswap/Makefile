NAME = push_swap
NAMEBONUS = checker
SRC = ./src/main.c ./src/parsing.c ./src/lists.c ./src/operations.c \
./src/operations1.c ./src/operations2.c \
./src/sort.c ./src/sort2.c ./src/utils.c \
./src/sort3.c ./src/sort4.c ./src/utils1.c ./src/utils2.c
BNS = ./bonus/main.c ./bonus/parsing.c ./bonus/lists.c ./bonus/operations.c ./bonus/operations1.c ./bonus/operations2.c \
./bonus/sort.c ./bonus/utils.c ./bonus/utils1.c ./bonus/utils2.c ./bonus/getoper.c \
./bonus/get_next_line_bonus/get_next_line_utils.c ./bonus/get_next_line_bonus/get_next_line.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
OBJ1 = $(BNS:.c=.o)

all: $(NAME)

$(NAMEBONUS): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAMEBONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

./bonus/%.o : ./bonus/%.c ./bonus/pushswap_bonus.h
	cc -Wall -Wextra -Werror -c $< -o $@

./src/%.o : ./src/%.c ./includes/pushswap.h
	cc -Wall -Wextra -Werror -c $< -o $@

bonus: $(NAMEBONUS)

clean:
	rm -f $(OBJ) $(OBJ1)

fclean : clean
	rm -rf $(NAME) $(NAMEBONUS)

re: fclean all