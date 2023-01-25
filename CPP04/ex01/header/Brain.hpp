/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:52 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 16:23:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();
		Brain		&operator=(Brain const &rhs);
		size_t		getBrainSizeFilled(void) const;
		void		addNewThinking(std::string think);
		std::string	getIdea(size_t index) const;
	protected:
		std::string	ideas[100];
	private:
		size_t		brainSizeFilled;
};

std::ostream &operator<<(std::ostream &o, Brain const &i);

#endif