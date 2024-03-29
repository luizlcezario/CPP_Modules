/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:47 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/13 10:18:51 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
	
class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const &src);

	~Fixed(void);
	Fixed	&operator=(Fixed const &src);


	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	static int const	fract_digits;
	int					fixed_point;
};

#endif