/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:13:11 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/26 23:29:25 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src) {
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	(void)rhs;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (this->getSigned() != true) 
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
			throw AForm::GradeTooLowException();
	else if ((1 + (std::rand() % 2)) == 1)
		std::cout << "Drillllllllll noises " << this->getTarget()
			<< " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Drillllllllll noises " << this->getTarget()
			<<" robotomized failed!" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return _target;
}