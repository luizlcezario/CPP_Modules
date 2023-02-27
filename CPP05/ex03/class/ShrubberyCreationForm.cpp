/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:13:11 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/26 23:30:04 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src) {
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), _target(target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	(void)rhs;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() == true) {
		if (executor.getGrade() <= this->getGradeToExecute()) {
			std::ofstream fd;
			std::string filename = this->getTarget() + "_shrubbery";
			fd.open(filename.c_str(), std::ios::out | std::ios::trunc);
			std::string tree = 
				"      ###      \n"
				"     ######    \n"
				"   ######O##   \n"
				"  ###########  \n"
				"   ##[]#####  \n"
				"    #[]@]##   \n"
				"     [][]     \n"
				"   [][][][]   \n";
			fd << tree;
			fd.close();
		}
		else
			throw AForm::GradeTooLowException();
	} else {
		throw AForm::FormNotSignedException();
	}
}

std::string	ShrubberyCreationForm::getTarget() const {
	return _target;
}