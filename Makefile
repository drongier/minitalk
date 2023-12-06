NAME = client

NAME_SERV = server

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = sources/client.c

SRC_SERV = sources/server.c

OBJ = $(patsubst %.c,%.o,$(wildcard $(SRC)))

OBJ_SERV = $(patsubst %.c,%.o,$(wildcard $(SRC_SERV)))

LIBRARY = libraries/ft_printf/*.c

all: $(NAME) $(NAME_SERV)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ) -o $(NAME)

$(NAME_SERV): $(OBJ_SERV)
	$(CC) $(CFLAGS) $(LIBRARY) $(OBJ_SERV) -o $(NAME_SERV)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_SERV)

fclean: clean
	rm -f $(NAME) $(NAME_SERV)

re: fclean all

.PHONY: all clean fclean re