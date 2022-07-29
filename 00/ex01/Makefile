CC = g++

NAME = phonelist

FLAGS = -Wall -Wextra -Werror  -std=c++11


CLASS = PhoneBook.cpp Contact.cpp

SRC =  main.cpp $(addprefix class/, $(CLASS))

all: 
	${CC} -I ./class ${FLAGS} ${SRC} -o $(NAME)


.PHONY: all