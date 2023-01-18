/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 09:38:34 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/02 20:51:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <iomanip>
# include "Contact.hpp"
using std::string;
using std::cout;
using std::setfill;
using std::setw;
using std::endl;


class PhoneBook {
	private:
		int		now;
		Contact	*contacts[8];
		void	PrintValue(string str);
	public:
		PhoneBook();
		~PhoneBook();
		void	AddContact();
		void	DisplayPhoneList();
		void	SelectContact();
};

#endif