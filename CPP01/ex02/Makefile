CC = g++

NAME = Brain

CFlAGS = -Wall -Wextra -Werror -std=c++11

SRC = main.cpp

OBJSDIR = obj/
OBJS = $(SRC:%.cpp=%.o)

all: $(OBJS)
	${CC} ${CFLAGS} ${addprefix $(OBJSDIR), $(OBJS)} -o $(NAME)

$(OBJS): $(OBJSDIR) $(SRC)
	$(CC) ${CFLAGS} -c $(SRC)
	mv $(OBJS) $(OBJSDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re