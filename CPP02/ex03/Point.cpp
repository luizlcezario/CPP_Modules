/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:59:37 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 11:38:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	return ;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {
	return ;
}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {
	return ;
}

Point::~Point() {
	return ;
}

Point	&Point::operator=(Point const &src) {
	const_cast<Fixed &>(this->_x) = src.getX();
	const_cast<Fixed &>(this->_y) = src.getY();
	return *this;
}

Fixed	Point::getX() const {
	return this->_x;
}

Fixed	Point::getY() const {
	return this->_y;
}
