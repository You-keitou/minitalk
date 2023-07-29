SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

all: $(NAME)

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	@${MAKE} -C printf
	$(CC) $(CFLAGS) $(OBJ_SERVER) printf/libftprintf.a -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@${MAKE} -C printf
	$(CC) $(CFLAGS) $(OBJ_CLIENT) printf/libftprintf.a -o $(NAME_CLIENT)

re: fclean all

clean:
	@${MAKE} -C printf clean
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@${MAKE} -C printf fclean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

.PHONY: all clean fclean re