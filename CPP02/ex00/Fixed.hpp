/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:47 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/12 20:11:50 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed {
public:
	void complain( std::string level );
private:
	static const	fract_digits;
	int				fixed_point;
	static void (Harl::*complaints[5])(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void unknown( void );
};

#endif