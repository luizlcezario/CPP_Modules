/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:02:31 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/27 21:57:38 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <fstream>
#include <ostream>
#include <sstream>
#include "Replace.hpp"

bool	openInSafety(std::ifstream &file, char *filename) {
	file.open(filename , std::ios::binary);
	if (file.fail()) {
		std::cerr << "Error: File " << filename << " not found." << std::endl;
		return (false);
	}
	return (true);
}

bool	openOutSafety(std::ofstream &file, char *filename) {
	std::string fileReplace = std::string(filename) + ".replace";

	file.open(fileReplace.c_str());
	if (file.fail()) {
		std::cerr << "Error: File " << filename << " not found." << std::endl;
		return (false);
	}
	return (true);
}

int	start_replacing(char *filename, std::string s1,std::string s2) {
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string 		str;

	if (openInSafety(ifs, filename) && openOutSafety(ofs, filename)) {
		while(std::getline(ifs,str))
		ofs << replacingAll(str, s1, s2) << std::endl;
		ifs.close();
		ofs.close();
		return (0);
	}
	else {
		return (1);
	}
	return (1);
}


int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Error: Wrong parameters" << std::endl;
		return (1);
	}
	else {
		return(start_replacing(argv[1], argv[2], argv[3]));
	}
}