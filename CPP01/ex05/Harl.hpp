/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:54:52 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 22:20:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
public:
	void complain( std::string level );
private:
	static const std::string levels[4];
	static void (Harl::*complaints[5])(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void unknown( void );
};


#endif