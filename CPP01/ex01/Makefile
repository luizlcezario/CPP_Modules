NAME			=	Zombie
SRC				=	main.cpp zombieHorde.cpp Zombie.cpp

SOURCES_DIR		=	./

OBJ_DIR			=	obj

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SRC))

OBJS			=	$(SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98   -g3


$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.cpp
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					rm -rf $(OBJ_DIR)

fclean:				clean
					rm -rf $(NAME)

re:					fclean all

.PHONY:				all clean fclean re