/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:26:50 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/29 10:27:25 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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
	Contact	contact = Contact();

	contacts.push_back(contact);
	if (contacts.size() > 8)
		contacts.pop_front();
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
	for (Contact tmp: contacts) {
		cout << "|";
		PrintValue(index);
		PrintValue(tmp.FirstName);
		PrintValue(tmp.LastName);
		PrintValue(tmp.Nickname);
		cout << endl;
		cout << setw(45) <<  setfill('-') << "-" << endl;
		index[0] = index[0] + 1;
	}
}

void	PhoneBook::SelectContact() {
	std::list<Contact>::iterator	it = contacts.begin();
	size_t							num_contact = 0;

	while (0 == num_contact || num_contact > contacts.size()) {
	cin >> num_contact;
	if(!(0 != num_contact && num_contact < contacts.size()))
		cout<< "please give a valid index"<<endl;
	}
	std::advance(it, num_contact - 1);
	it->Contact::DisplayContact();
}

