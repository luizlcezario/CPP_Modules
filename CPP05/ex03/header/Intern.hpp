/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:34:10 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/27 00:17:57 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{

public:
	Intern();
	~Intern();
	Intern(Intern const &src);
	Intern &operator=(Intern const &rhs);
	AForm *makeForm(std::string form, std::string target);

private:
	static AForm *makeShrubbery(std::string target) ;
	static AForm *makeRobotomy(std::string target) ;
	static AForm *makePresidential(std::string target) ;
	static const std::string _forms[3];
	static AForm* (*_formFunc[3])(std::string);
};



#endif