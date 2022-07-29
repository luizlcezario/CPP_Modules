/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:38:52 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/29 10:28:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneLine(PhoneBook phoneBook) {
	string	command;

	cout<<"Please use one of the follow Commands:"<<endl;
	cout<<"\tADD"<<endl <<"\tSEARCH"<<endl <<"\tEXIT"<<endl;
	std::getline(cin, command);
	while (command.compare("EXIT")) {
		if (!command.compare("ADD"))
			phoneBook.PhoneBook::AddContact();
		else if (!command.compare("SEARCH")) {
			phoneBook.PhoneBook::DisplayPhoneList();
			phoneBook.PhoneBook::SelectContact();
		}
		else {
			std::getline(cin, command);
			continue;
		}
		cout<<"Please use one of the follow Commands:"<<endl;
		cout<<"\tADD"<<endl <<"\tSEARCH"<<endl <<"\tEXIT"<<endl;
		command = "";
		std::getline(cin, command);
	}
}

int main (int argc, char **str) {
	PhoneBook phoneBook;

	(void) str;
	if (argc == 1)
		PhoneLine(phoneBook);
	else {
		cout<<"Error: Many arguments"<<endl;
		return 1;
	}
	return 0;
}