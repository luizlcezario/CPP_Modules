NAME	= Account
CC		= g++
FLAGS 	= -Wall -Wextra -Werror  -std=c++11
CLASS	= Account.cpp 
SRC		= test/tests.cpp $(addprefix class/, $(CLASS))
OBJSDIR	= obj/
HEADER = class
OBJS	= tests.o  $(CLASS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	${CC} -I $(HEADER) ${SRC} ${FLAGS} -o $(NAME)

$(OBJS): $(OBJSDIR) $(SRC)
	$(CC) -I $(HEADER) $(CFLAGS) -c $(SRC)
	mv $(OBJS) $(OBJSDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 