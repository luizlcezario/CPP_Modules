/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:38:52 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/28 23:16:48 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <iomanip>

using std::string;
using std::cout;
using std::setfill;
using std::setw;
using std::endl;
using std::cin;

class Contact
{
public:
	string	FirstName = "";
	string	LastName = "";
	string	Nickname = "";
	string	PhoneNumber = "";
	string	DarkestSecret = "";
	Contact() {
		cout<<"Please Enter with the FirstName of the Contact:"<<endl;
		cin>>FirstName;
		cout<<"Please Enter with the LastName of the Contact:"<<endl;
		cin>>LastName;
		cout<<"Please Enter with the Nickname of the Contact:"<<endl;
		cin>>Nickname;
		cout<<"Please Enter with the PhoneNumber of the Contact:"<<endl;
		cin>>PhoneNumber;
		cout<<"Please Enter with the DarkestSecret of the Contact:"<<endl;
		cin>>DarkestSecret;
	}
	void DisplayContact() {
		cout<< "First name:\t" << FirstName <<endl;
		cout<< "Last name:\t" << LastName <<endl;
		cout<< "Nickname:\t" << Nickname <<endl;
		cout<< "PhoneNumber:\t" << PhoneNumber <<endl;
		cout<< "DarkestSecret:\t" << DarkestSecret <<endl;
	}
};

class PhoneBook {
	private:
		std::list<Contact> contacts;
		void PrintValue(string str) {
			if (str.length() > 10) {
				str = str.substr(0, 8) + ".";
			}
			cout << setfill(' ') << setw(10) << str << "|";
		}
	public:
		void AddContact() {
			Contact	contact = Contact();

			contacts.push_back(contact);
			if (contacts.size() > 8)
				contacts.pop_front();
		}
		void	DisplayPhoneList() {
			string	index = "1";
			size_t	num_contact = 0;
			std::list<Contact>::iterator it = contacts.begin();

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
			while (0 == num_contact || num_contact > contacts.size()) {
				cin >> num_contact;
				if(!(0 != num_contact && num_contact < contacts.size()))
					cout<< "please give a valid index"<<endl;
			}
			std::advance(it, num_contact - 1);
			it->Contact::DisplayContact();
		}
};

void	PhoneLine(PhoneBook phoneBook) {
	string	command;

	cout<<"Please use one of the follow Commands:"<<endl;
	cout<<"\tADD"<<endl <<"\tSEARCH"<<endl <<"\tEXIT"<<endl;
	std::getline(cin, command);
	while (command.compare("EXIT")) {
		if (!command.compare("ADD")) {
			phoneBook.PhoneBook::AddContact();
		} else if (!command.compare("SEARCH")) {
			phoneBook.PhoneBook::DisplayPhoneList();
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