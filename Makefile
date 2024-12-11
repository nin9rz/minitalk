NAMECLIENT = client
NAMESERVER = server

SOURCES = 	src/ft_printf_utils.c\
			src/ft_printf.c\

SERVER = server.c
CLIENT = client.c

SERVEROBJ = $(SERVER:.c=.o)
CLIENTOBJ = $(CLIENT:.c=.o)
OBJECTS = $(SOURCES:.c=.o)
OBJECTSALL = $(SERVEROBJ) $(CLIENTOBJ) $(OBJECTS)

CC = cc
CFLAGS = -Werror -Wall -Wextra -g

CSRC = 	src/ft_printf_utils.c\

all: $(NAMECLIENT) $(NAMESERVER)

$(NAMECLIENT): $(OBJECTSALL)
		@$(CC) $(CFLAGS) $(OBJECTS) $(CLIENTOBJ) -o $(NAMECLIENT)
		@printf "\rCompiled Client ✅\n"

$(NAMESERVER): $(OBJECTSALL)
		@$(CC) $(CFLAGS) $(OBJECTS) $(SERVEROBJ) -o $(NAMESERVER)
		@printf "\rCompiled Server ✅\n"

clean:
		@rm -f $(OBJECTSALL)
		@rm -f $(OBJECTSALLBONUS)
		@printf "Cleaned objects ✅\n"

fclean:	clean
		@rm -f $(NAMESERVER)
		@rm -f $(NAMECLIENT)
		@printf "Cleaned executables ✅\n"

re: fclean all

nin9rz :
	@printf "\033[0;34m\n"
	@echo "                     __                    "
	@echo "       __          /'_ `\                  "
	@echo "  ___ /\_\    ___ /\ \L\ \  _ __   ____    "
	@echo "/' _ `\/\ \ /' _ `\ \___, \/\`'__\/\_ ,`\  "
	@echo "/\ \/\ \ \ \/\ \/\ \/__,/\ \ \ \/ \/_/  /_ "
	@echo "\ \_\ \_\ \_\ \_\ \_\   \ \_\ \_\   /\____\"
	@echo " \/_/\/_/\/_/\/_/\/_/    \/_/\/_/   \/____/"
	@printf "\033[0m\n"

.PHONY: all clean fclean re nin9rz
