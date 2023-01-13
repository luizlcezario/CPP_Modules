/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:42 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 10:36:13 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fract_digits = 8;

Fixed::Fixed(void) : fixed_point(0) {
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n) {
  std::cout << "Int constructor called" << std::endl;
  this->fixed_point << fract_digits;
}

Fixed::Fixed(float const n) {
  std::cout << "Float constructor called" << std::endl;
  this->fixed_point = static_cast<int>(roundf(n * (1 << fract_digits)));
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

int Fixed::toInt(void) const {
  return (this->fixed_point >> fract_digits);
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->fixed_point) / (1 << fract_digits));
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits menber function caled" << std::endl;
	return(this->fixed_point);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
	return ;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
  o << i.toFloat();
  return (o);
}
