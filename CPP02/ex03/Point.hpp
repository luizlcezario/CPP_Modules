/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:11:02 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 11:11:42 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP


class Point
{
public:
	Point();
	Point(Point const &src);
	~Point();
	Point	&operator=(Point const &src);

private:

};

#endif