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
	cout << "Please Enter with the FirstName of the Contact:" << endl;
	cin >> FirstName;
	cout << "Please Enter with the LastName of the Contact:" << endl;
	cin >> LastName;
	cout << "Please Enter with the Nickname of the Contact:" << endl;
	cin >> Nickname;
	cout << "Please Enter with the PhoneNumber of the Contact:" << endl;
	cin >> PhoneNumber;
	cout << "Please Enter with the DarkestSecret of the Contact:" << endl;
	cin >> DarkestSecret;
}
/**
 * @brief This the Contact one line for infos.
 * 
 */
void Contact::DisplayContact() {
	cout << "First name:\t" << FirstName << endl;
	cout << "Last name:\t" << LastName << endl;
	cout << "Nickname:\t" << Nickname << endl;
	cout << "PhoneNumber:\t" << PhoneNumber << endl;
	cout << "DarkestSecret:\t" << DarkestSecret << endl;
}
