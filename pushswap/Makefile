NAME = push_swap
SRC = ./src/main.c ./src/parsing.c ./src/lists.c ./src/operations.c ./src/operations1.c ./src/operations2.c ./src/sort.c ./src/sort2.c ./src/utils.c ./src/sort3.c ./src/sort4.c ./src/utils1.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c pushswap.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all