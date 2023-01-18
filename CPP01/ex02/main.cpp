/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:59:57 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:40:05 by llima-ce         ###   ########.fr       */
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
	cout << "The memory address of the string variable: " << &brain << endl;
	cout << "The memory address held by stringPTR:      " << stringPTR << endl;
	cout << "The memory address held by stringREF:      " << &stringREF << endl;
	cout << endl;
	cout << "The value of the string variable:          " << brain << endl;
	cout << "The value pointed to by stringPTR:         " << *stringPTR << endl;
	cout << "The value pointed to by stringREF:         " << stringREF << endl;
	return (0);
}