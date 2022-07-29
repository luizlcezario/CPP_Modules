/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:38:34 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/29 10:27:35 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <list>
# include <iomanip>
# include "Contact.hpp"
using std::string;
using std::cout;
using std::setfill;
using std::setw;
using std::endl;


class PhoneBook {
	private:
		std::list<Contact> contacts;
		void	PrintValue(string str);
	public:
		void	AddContact();
		void	DisplayPhoneList();
		void	SelectContact();
};

#endif