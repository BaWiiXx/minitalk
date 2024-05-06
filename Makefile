NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRC_SERVER = server.c
SRC_CLIENT = client.c
SRC_SERVER_BONUS = server_bonus.c
SRC_CLIENT_BONUS = client_bonus.c

OBJ_SERVER=$(SRC_SERVER:.c=.o)
OBJ_CLIENT=$(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS=$(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS=$(SRC_CLIENT_BONUS:.c=.o)


RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -I/./libft/libft.h

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER): $(OBJ_SERVER)
	make --directory ./libft
	$(CC) $(OBJ_SERVER) $(CFLAGS) -o $(NAME_SERVER) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of server successful!\033[0m"; \
	fi

$(NAME_CLIENT): $(OBJ_CLIENT)
	make --directory ./libft
	$(CC) $(OBJ_CLIENT) $(CFLAGS) -o $(NAME_CLIENT) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of client successful!\033[0m"; \
	fi

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS)
	make --directory ./libft
	$(CC) $(OBJ_SERVER_BONUS) $(CFLAGS) -o $(NAME_SERVER_BONUS) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of server bonus successful!\033[0m"; \
	fi

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	make --directory ./libft
	$(CC) $(OBJ_CLIENT_BONUS) $(CFLAGS) -o $(NAME_CLIENT_BONUS) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of client bonus successful!\033[0m"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	$(RM) libft/*.o
	$(RM) libft/*.a

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

run: $(NAME)
	./$(NAME_SERVER)
	./$(NAME_CLIENT)

.PHONY: all bonus clean fclean re
