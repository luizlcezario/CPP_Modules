/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:42 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 10:17:46 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fract_digits = 8;

Fixed::Fixed(void) : fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits menber function caled" << std::endl;
	return(this->fixed_point);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
	return ;
}