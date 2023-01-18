/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:56:49 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 12:07:48 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// calculate the area of the triangle is |d|/2
// |x1  y1  1| x1 y1
// |x2  y2  1| x2 y2
// |x3  y3  1| x3 y3
static float	area(Point const a, Point const b, Point 	const c)
{
	return fabs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	float total_area = area(a, b, c);

	float a1 = area(point, b, c);
	float a2 = area(a, point, c);
	float a3 = area(a, b, point);
	if (a1 == 0 || a2 == 0 || a3 == 0)
		return (false);
	return (total_area == a1 + a2 + a3 ? true : false);
}