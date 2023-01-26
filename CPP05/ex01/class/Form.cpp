/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:57 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 15:44:29 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, size_t gradeToSign, size_t gradeToExecute) : _name(name) , _signed(false) , _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) {
	*this = src;
}

Form::~Form() {}

Form &Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		const_cast<std::string&> (this->_name) = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::getSigned() const {
	return _signed;
}

size_t		Form::getGradeToSign() const {
	return _gradeToSign;
}

size_t		Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void		Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Form const &rhs) {
	out << rhs.getName() << (rhs.getSigned() ? " is signed" : " is not signed" )<< " and requires a grade of " << rhs.getGradeToSign() << " to sign and " << rhs.getGradeToExecute() << " to execute.";
	return (out);
}
