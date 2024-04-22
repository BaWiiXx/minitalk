NAME = minitalk

SRCS = client.c serveur.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -Wall -Wextra -Werror -I./ft_printf/printf.h

all: $(NAME)

$(NAME) : $(OBJS)
	make --directory ./printf
	$(CC) $(OBJS) $(CFLAGS) -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

run: all
	./$(NAME)

.PHONY: all clean fclean re