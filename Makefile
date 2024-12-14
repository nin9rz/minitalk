NAMECLIENT = client
NAMESERVER = server

SOURCES = 	src/ft_printf_utils.c\
			src/ft_printf.c			

LIBFT =	src/libft/libft.a

INCLUDE = -Isrc/libft/ -I.

SERVER = server.c
CLIENT = client.c

SERVEROBJ = $(SERVER:.c=.o)
CLIENTOBJ = $(CLIENT:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
OBJECTSALL = $(SERVEROBJ) $(CLIENTOBJ) $(OBJECTS)

CC = cc
CFLAGS = -Werror -Wall -Wextra -g 

CSRC = 	src/ft_printf_utils.c

%.o:%.c
	$(CC) $(CFLAGS) $< $(INCLUDE) -c -o $@

all: $(NAMECLIENT) $(NAMESERVER)

$(LIBFT):
	make -C src/libft/

$(NAMECLIENT): $(LIBFT) $(OBJECTSALL)
		$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(CLIENTOBJ) $(LIBFT) -o $(NAMECLIENT)
		@printf "\rCompiled Client ✅\n"

$(NAMESERVER): $(LIBFT) $(OBJECTSALL)
		$(CC) $(CFLAGS) $(OBJECTS) $(INCLUDE) $(SERVEROBJ) $(LIBFT) -o $(NAMESERVER)
		@printf "\rCompiled Server ✅\n"

clean:
		@rm -f $(OBJECTSALL)
		@rm -f $(OBJECTSALLBONUS)
		@make -C src/libft/ clean
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAMESERVER)
		@rm -f $(NAMECLIENT)
		@make -C src/libft/ fclean
		@printf "Cleaned executables ✅\n"

re: fclean all

nin9rz :
	@printf "\033[0;34m\n"
	@echo "                     __                    "
	@echo "       __          /'_ \`\                  "
	@echo "  ___ /\_\    ___ /\ \ \ \  _ __   ____    "
	@echo "/' _ \`\/\ \ /' _ \`\ \___, \/\`'__\/\_ ,\`\  "
	@echo "/\ \/\ \ \ \/\ \/\ \/__,/\ \ \ \/ \/_/  /_ "
	@echo "\ \_\ \_\ \_\ \_\ \_\   \ \_\ \_\   /\____\\"
	@echo " \/_/\/_/\/_/\/_/\/_/    \/_/\/_/   \/____/"
	@printf "\033[0m\n"

.PHONY: all clean fclean re nin9rz
