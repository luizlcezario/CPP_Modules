/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:26:50 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/02 20:48:54 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	now = 0;
}

PhoneBook::~PhoneBook() {
	while (now > 0) {
		now--;
		delete contacts[now];
	}
}

/**
 * @brief private function to format and print the infos for the view of 
 * Contacts
 * 
 * @param str to be print for the table view
 */
void	PhoneBook::PrintValue(string str) {
	if (str.length() > 10)
		str = str.substr(0, 8) + ".";
	cout << setfill(' ') << setw(10) << str << "|";
}

/**
 * @brief Add a new Contact to the list of the PhoneBook 
 * 
 */
void	PhoneBook::AddContact() {
	Contact	*contact = new Contact();

	if (now > 7) {
		delete contacts[1];
		for (int i = 1; i < now; i++) {
			contacts[i] = contacts[i + 1];
		}
		now--;
	}
	contacts[now] = contact;
	now++;
}

/**
 * @brief Display all Contacts in the list with index, Name, last name,
 * and Nickname.
 * 
 */
void	PhoneBook::DisplayPhoneList() {
	string	index = "1";

	cout << setfill('_') << setw(45) << "_" << endl;
	cout << "|  index   |first name|last name | nickname |"<< endl;
	cout << setfill('-') << setw(45) << "-" << endl;
	for (int i = 0; i < now; i++) {
		cout << "|";
		PrintValue(index);
		PrintValue(contacts[i]->FirstName);
		PrintValue(contacts[i]->LastName);
		PrintValue(contacts[i]->Nickname);
		cout << endl;
		cout << setw(45) <<  setfill('-') << "-" << endl;
		index[0] = index[0] + 1;
	}
}

void	PhoneBook::SelectContact() {
	int		num_contact = 0;

	while ( num_contact == 0 || num_contact > now ) {
		if ( num_contact != 0 )
			cout<< "please give a valid index"<<endl;
		cin >> num_contact;
	}
	contacts[num_contact - 1]->DisplayContact();
}

