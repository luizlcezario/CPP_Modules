/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:47 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 11:01:22 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <cmath>

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const &src);
	explicit	Fixed(const int src);
	explicit	Fixed(const float src);
	~Fixed(void);
	Fixed	&operator=(Fixed const &src);
	bool	operator>(Fixed const &src) const;
	bool	operator<(Fixed const &src) const;
	bool	operator<=(Fixed const &src) const;
	bool	operator>=(Fixed const &src) const;
	bool	operator!=(Fixed const &src) const;
	bool	operator==(Fixed const &src) const;

	Fixed	operator+(Fixed const &src) const;
	Fixed	operator-(Fixed const &src) const;
	Fixed	operator/(Fixed const &src) const;
	Fixed	operator*(Fixed const &src) const;

	Fixed	&operator++(void); // prefix
	Fixed	operator++(int); // posfix
	Fixed	&operator--(void); // prefix
	Fixed	operator--(int); // posfix


	static	Fixed &min(Fixed &dst, Fixed &lst);
	static	Fixed const &min(Fixed const &dst, Fixed const &lst);
	static	Fixed &max(Fixed &dst, Fixed &lst);
	static	Fixed const &max(Fixed const &dst, Fixed const &lst);

	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	static int const	fract_digits;
	int					fixed_point;
};

std::ostream &operator<<(std::ostream &o, Fixed const &src);

#endif