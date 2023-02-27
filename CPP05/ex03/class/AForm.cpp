/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:06:57 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/26 23:12:07 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, size_t gradeToSign, size_t gradeToExecute) : _name(name) , _signed(false) , _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) {
	*this = src;
}

AForm::~AForm() {}

AForm &AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		const_cast<std::string&> (this->_name) = rhs.getName();
		this->_signed = rhs.getSigned();
		this->_gradeToSign = rhs.getGradeToSign();
		this->_gradeToExecute = rhs.getGradeToExecute();
	}
	return *this;
}

std::string	AForm::getName() const {
	return _name;
}

bool		AForm::getSigned() const {
	return _signed;
}

size_t		AForm::getGradeToSign() const {
	return _gradeToSign;
}

size_t		AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void		AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what(void) const throw() {
	return "Grade too high";
}

const char* AForm::FormNotSignedException::what(void) const throw() {
	return "Please Sign the form first";
}

const char* AForm::GradeTooLowException::what(void) const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, AForm const &rhs) {
	out << rhs.getName() << (rhs.getSigned() ? " is signed" : " is not signed" )<< " and requires a grade of " << rhs.getGradeToSign() << " to sign and " << rhs.getGradeToExecute() << " to execute.";
	return (out);
}
