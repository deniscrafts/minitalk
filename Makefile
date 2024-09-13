CC				=	 	gcc
FLAGS			=		-Wextra -Werror -Wall
RM				=		rm -f

NAME_SERVER     =		server
SERVER_SRC      =       server.c
SERVER_OBJ      =       $(SERVER_SRC:.c=.o)

NAME_CLIENT		=		client
CLIENT_SRC      =       client.c
CLIENT_OBJ      =       $(CLIENT_SRC:.c=.o)

UTILS_SRC       =       utils.c
UTILS_OBJ       =       $(UTILS_SRC:.c=.o)

all: 		$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(NAME_SERVER)
	
$(NAME_CLIENT):	$(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(NAME_CLIENT)

	@echo "Done!"
	
clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "Done!"
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "Done!"

re: fclean all

.PHONY:		all clean fclean re
