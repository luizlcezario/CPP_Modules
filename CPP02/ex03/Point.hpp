/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:11:02 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 11:14:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(Point const &src);
	Point(Fixed const &x, Fixed const &y);
	~Point();
	Point	&operator=(Point const &src);
	Fixed	getX() const;
	Fixed	getY() const;

private:
	const Fixed _x;
	const Fixed _y;
};

#endif