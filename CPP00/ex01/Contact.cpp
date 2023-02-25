/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:40:03 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/29 10:22:18 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
/**
 * @brief Construct a new Contact:: Contact object
 * 
 */
Contact::Contact() {
	this->FirstName = Contact::validationField( "Please Enter with the FirstName of the Contact:", NAME);
	this->LastName = Contact::validationField( "Please Enter with the LastName of the Contact:", NAME);
	this->Nickname = Contact::validationField( "Please Enter with the Nickname of the Contact:");
	this->PhoneNumber = Contact::validationField( "Please Enter with the PhoneNumber of the Contact:", PHONE);
	this->DarkestSecret = Contact::validationField( "Please Enter with the DarkestSecret of the Contact:");
}

Contact::Contact(Contact const &src) {
	*this = src;
}

Contact::~Contact() {}

Contact &Contact::operator=(Contact const &rhs) {
	if (this != &rhs) {
		this->FirstName = rhs.FirstName;
		this->LastName = rhs.LastName;
		this->Nickname = rhs.Nickname;
		this->PhoneNumber = rhs.PhoneNumber;
		this->DarkestSecret = rhs.DarkestSecret;
	}
	return *this;
}

/**
 * @brief This the Contact one line for infos.
 * 
 */
void Contact::displayContact() {
	cout << "First name\t" << getFirstName() << endl;
	cout << "Last name:\t" << getLastName() << endl;
	cout << "Nickname:\t" << getNickname() << endl;
	cout << "PhoneNumber:\t" << getPhoneNumber() << endl;
	cout << "DarkestSecret:\t" << getDarkestSecret() << endl;
}

static bool isValidPhoneNumber(string field) {
	if (field.length() != 10 && field.length() != 11) {
		std::cout << "A valid phone number need to have 10 or 11 digits! please try again!" << std::endl;
		return false;
	} 
	for (std::string::iterator it=field.begin(); it != field.end(); ++it) {
		if(!std::isdigit(*it)) {
			std::cout << "This field is only for numbers! please Try again!" << std::endl;
			return false;
		}
	}
	return true;
}

static bool	isValidName(string field) {
	for (std::string::iterator it=field.begin(); it != field.end(); ++it) {
		if(!std::isalpha(*it)) {
			std::cout << "This field is only for letters! please try again!" << std::endl;
			return false;
		}
	}
	return true;
}

string Contact::validationField(string field, e_field type) {
	string input;
	bool valid = false;

	cout << field << endl;
	std::getline(cin, input);
	if (input.empty()) {
		cout << "This field is required! please try again!" << endl;
		return validationField(field, type);
	}
	valid = type == NAME ? isValidName(input) : type == PHONE ? isValidPhoneNumber(input) : true;
	if (!valid) 
		return validationField(field, type);
	return input;
}


string Contact::getDarkestSecret() {
	return this->DarkestSecret;
}

string Contact::getPhoneNumber() {
	return this->PhoneNumber;
}

string Contact::getNickname() {
	return this->Nickname;
}

string Contact::getLastName() {
	return this->LastName;
}

string Contact::getFirstName() {
	return this->FirstName;
}