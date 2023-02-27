/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:34:32 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 15:23:19 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		std::string const	_name;
		size_t				_grade;
	public:
		Bureaucrat();
		explicit Bureaucrat(std::string name, size_t grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string	getName() const;
		size_t		getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);
		class GradeTooHighException : public std::exception {
		public:
			const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif