NAME = Minitalk
SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS			=	util.c
SERVER_SRCS		=	server.c
CLIENT_SRCS     =   client.c
SRCS_BONUS			=	util_bonus.c
SERVER_SRCS_BONUS		=	server_bonus.c
CLIENT_SRCS_BONUS     =   client_bonus.c

OBJS = $(SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

ifeq ($(MAKECMDGOALS), bonus)
	OBJS = $(OBJS_BONUS)
	SERVER_OBJS = $(SERVER_OBJS_BONUS)
	CLIENT_OBJS = $(CLIENT_OBJS_BONUS)
endif

all: $(NAME)
bonus: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(OBJS) -o $(SERVER) ./ft_printf/libftprintf.a

$(CLIENT): $(CLIENT_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(OBJS) -o $(CLIENT) ./ft_printf/libftprintf.a

clean:
	rm -f $(OBJS) $(SERVER_OBJS) $(CLIENT_OBJS) $(OBJS_BONUS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@$(MAKE) clean -C ./ft_printf

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	@$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re
