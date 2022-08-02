/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:06:55 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 23:17:19 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char const *argv[]) {
	Harl harl;

	if(argc != 2) {
		std::cerr << "error : invalid number of arguments" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}