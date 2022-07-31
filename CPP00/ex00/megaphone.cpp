/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:42:28 by llima-ce          #+#    #+#             */
/*   Updated: 2022/07/28 11:58:57 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
	if(argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for(int a = 1; a < argc; a++) {
		for(int i = 0; argv[a][i] != 0; i++)
			std::cout<<(char)toupper(argv[a][i]);
	}
	std::cout<<std::endl;
	return (0);
}