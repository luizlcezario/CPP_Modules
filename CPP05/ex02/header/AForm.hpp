/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:59:11 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/26 23:11:33 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		size_t				_gradeToSign;
		size_t				_gradeToExecute;
	public:
		virtual void execute(Bureaucrat const &executor) const = 0;
		AForm();
		explicit AForm(std::string name, size_t gradeToSign, size_t gradeToExecute);
		AForm(AForm const &src);
		~AForm();
		AForm &operator=(AForm const &rhs);

		std::string	getName() const;
		bool		getSigned() const;
		size_t		getGradeToSign() const;
		size_t		getGradeToExecute() const;
		void		beSigned(Bureaucrat const &bureaucrat);
		class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
		};
		
		class FormNotSignedException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &rhs);

#endif