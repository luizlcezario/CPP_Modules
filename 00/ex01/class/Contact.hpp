/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:40:35 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/29 10:21:17 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/**
 * @brief Class that representation of a Contact for a list of Contacts.
 */
class Contact
{
public:
	string	FirstName;
	string	LastName;
	string	Nickname;
	string	PhoneNumber;
	string	DarkestSecret;
	// constructor
	Contact();
	// view contact
	void DisplayContact();
};

#endif