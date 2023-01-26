/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:48:07 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/25 16:27:23 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i].clear();
	brainSizeFilled = 0;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	this->brainSizeFilled = rhs.getBrainSizeFilled();
	return *this;
}

size_t Brain::getBrainSizeFilled(void) const
{
	return this->brainSizeFilled;
}

std::string Brain::getIdea(size_t size) const
{
	if (size > 100)
		return "This is more than my brain can handle!";
	else if (size > brainSizeFilled)
		return "This is more than think so far!";
	else
		return this->ideas[size];
}

void Brain::addNewThinking(std::string idea)
{
	if (brainSizeFilled < 100)
	{
		ideas[brainSizeFilled] = idea;
		this->brainSizeFilled++;
	}
}

std::ostream &operator<<(std::ostream &o, Brain const &i) {
	o << "My think so far: ";
	for (size_t j = 0; j < i.getBrainSizeFilled(); j++)
		o << std::endl << i.getIdea(j);
	return o;
}
