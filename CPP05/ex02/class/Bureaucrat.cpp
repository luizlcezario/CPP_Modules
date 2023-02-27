/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:44:07 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 15:42:42 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

size_t		Bureaucrat::getGrade() const {
	return _grade;
}

void		Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void		Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Grade too low!";
}

void		Bureaucrat::signForm(Form &form) {
	if (form.getSigned() == false) {
		try {
			form.beSigned(*this);
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		}
	} else {
		std::cout << _name << " cannot sign " << form.getName() << " because it is already signed." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs) {
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}
