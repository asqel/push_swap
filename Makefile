NAME = push_swap

SRC = \
	args.c \
	atoi.c \
	display.c \
	main.c \
	operations2.c \
	operations3.c \
	operations.c \
	smol_sort.c \
	sort.c \
	sort_utils2.c \
	sort_utils3.c \
	sort_utils.c \
	stack.c

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
