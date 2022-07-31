CC = g++
NAME = phonelist
FLAGS = -Wall -Wextra -Werror  -std=c++11 -I class
CLASS = PhoneBook.cpp Contact.cpp
MAIN = main.cpp
SRC =  $(MAIN) $(addprefix class/, $(CLASS))
OBJS	= $(CLASS:%.cpp=%.o)
OBJSDIR	= obj/
HEADER = class
all: $(NAME)

$(NAME): $(OBJS)
	${CC} -I $(HEADER) ${addprefix $(OBJSDIR), $(OBJS)} $(MAIN) ${FLAGS} -o $(NAME)

$(OBJS): $(OBJSDIR) 
	$(CC) -I $(HEADER) $(FLAGS) -c $(addprefix class/, $(CLASS))
	mv $(OBJS) $(OBJSDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re