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

typedef enum {
	NAME,
	PHONE,
	OTHER
} e_field;
/**
 * @brief Class that representation of a Contact for a list of Contacts.
 */
class Contact
{
public:
	Contact();
	Contact(Contact const &src);
	~Contact();
	Contact &operator=(Contact const &rhs);
	void	displayContact();
	string	getFirstName();
	string	getLastName();
	string	getNickname();
	string	getPhoneNumber();
	string	getDarkestSecret();
private:
	static string	validationField(string field, e_field type = OTHER);
	string			FirstName;
	string			LastName;
	string			Nickname;
	string			PhoneNumber;
	string			DarkestSecret;
};

#endif