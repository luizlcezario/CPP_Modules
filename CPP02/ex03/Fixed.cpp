/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:42 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 11:07:49 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::fract_digits = 8;

Fixed::Fixed(void) : fixed_point(0) {
	return;
}

Fixed::Fixed(int const n) {
  this->fixed_point = n << fract_digits;
}

Fixed::Fixed(float const n) {
  this->fixed_point = static_cast<int>(roundf(n * (1 << fract_digits)));
}

Fixed::Fixed(Fixed const &src) {
	*this = src;
}

Fixed::~Fixed(void) {
	return ;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	this->setRawBits(src.getRawBits());
	return (*this);
}

bool	Fixed::operator>(Fixed const &src) const {
	return (this->fixed_point > src.getRawBits());
}

bool	Fixed::operator<(Fixed const &src) const {
	return (this->fixed_point < src.getRawBits());
}

bool	Fixed::operator>=(Fixed const &src) const {
	return (this->fixed_point >= src.getRawBits());
}

bool	Fixed::operator<=(Fixed const &src) const {
	return (this->fixed_point <= src.getRawBits());
}

bool	Fixed::operator==(Fixed const &src) const {
	return (this->fixed_point == src.getRawBits());
}

bool	Fixed::operator!=(Fixed const &src) const {
	return (this->fixed_point != src.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &src) const {
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(Fixed const &src) const {
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(Fixed const &src) const {
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(Fixed const &src) const {
	return (Fixed(this->toFloat() / src.toFloat()));
}

Fixed	&Fixed::operator++(void) {
	this->fixed_point++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	this->fixed_point++;
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	this->fixed_point--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixed_point--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &dst, Fixed &lst) {
	return (dst.getRawBits() < lst.getRawBits() ? dst : lst);
}

Fixed	&Fixed::max(Fixed &dst, Fixed &lst) {
	return (dst.getRawBits() > lst.getRawBits() ? dst : lst);
}

Fixed const	&Fixed::min(Fixed const &dst, Fixed const &lst) {
	return (dst.getRawBits() < lst.getRawBits() ? dst : lst);
}

Fixed const	&Fixed::max(Fixed const &dst, Fixed const &lst) {
	return (dst.getRawBits() > lst.getRawBits() ? dst : lst);
}

int Fixed::toInt(void) const {
  return (this->fixed_point >> fract_digits);
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(this->fixed_point) / (1 << fract_digits));
}

int		Fixed::getRawBits(void) const {
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
