/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:59:11 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/20 18:15:36 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		std::string const	_name;
		bool				_signed;
		size_t const		_gradeToSign;
		size_t const		_gradeToExecute;
	public:
		Form();
		explicit Form(std::string name, size_t gradeToSign, size_t gradeToExecute);
		Form(Form const &src);
		~Form();
		
		Form &operator=(Form const &rhs);

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
};

std::ostream &operator<<(std::ostream &out, Form const &rhs);

#endif