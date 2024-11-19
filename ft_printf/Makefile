NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS			=	main.c \
					put_string.c \
					put_decimal.c \
					put_hexadecimal.c
       
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
