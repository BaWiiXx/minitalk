NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER=$(SRC_SERVER:.c=.o)
OBJ_CLIENT=$(SRC_CLIENT:.c=.o)


RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -I./ft_printf/ft_printf.h\
							-I/./libft/libft.h

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	make --directory ./ft_printf
	make --directory ./libft
	$(CC) $(OBJ_SERVER) $(CFLAGS) -o $(NAME_SERVER) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of server successful!\033[0m"; \
	fi

$(NAME_CLIENT): $(OBJ_CLIENT)
	make --directory ./ft_printf
	make --directory ./libft
	$(CC) $(OBJ_CLIENT) $(CFLAGS) -o $(NAME_CLIENT) libft/libft.a
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation of client successful!\033[0m"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	$(RM) libft/*.o
	$(RM) libft/*.a

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

run: $(NAME)
	./$(NAME_SERVER)
	./$(NAME_CLIENT)

.PHONY: all clean fclean re