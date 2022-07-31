/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:59:57 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/31 17:07:09 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void) {
	string brain = "HI THIS IS BRAIN";
	string *stringPTR = &brain;
	string& stringREF = brain;
	cout << "address from string: " << &brain << endl;
	cout << "address from stringPTR: " << stringPTR << endl;
	cout << "address from stringPTR: " << stringPTR << endl;
	cout << "value from string: " << brain << endl;
	cout << "value from stringPTR: " << *stringPTR << endl;
	cout << "value from stringPTR: " << *stringPTR << endl;
	
	return (0);
}