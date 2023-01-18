/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:55:51 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/18 14:02:01 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a( Fixed( 0 ), Fixed( 1 ));
	Point a2( Fixed( 0 ), Fixed( 2 ));
	Point b( Fixed( 2 ), Fixed( 4 ));
	Point b2( Fixed( -2 ), Fixed( 0 ));
	Point c( Fixed( -7 ), Fixed( 3 ));
	Point c2( Fixed( 2 ), Fixed( 0 ));
	Point test1( Fixed( 0 ), Fixed( 0 ));
	Point test2( Fixed( 0 ), Fixed( 1 ));
	Point test3( Fixed( 0 ), Fixed( 2 ));
	Point test4( Fixed( -3 ), Fixed( 2 ));
	Point test5( Fixed( 100 ), Fixed( 1 ));
	
	std::cout << "test 1 " << bsp(a ,b ,c ,test1) << std::endl;
	std::cout << "test 2 " << bsp(a ,b ,c ,test2) << std::endl;
	std::cout << "test 3 " << bsp(a ,b ,c ,test3) << std::endl;
	std::cout << "test 4 " << bsp(a ,b ,c ,test4) << std::endl;
	std::cout << "test 5 " << bsp(a ,b ,c ,test5) << std::endl;
	std::cout << "test 6 " << bsp(a2 ,b2 ,c2 ,test1) << std::endl;
	std::cout << "test 7 " << bsp(a2 ,b2 ,c2 ,test2) << std::endl;
	std::cout << "test 8 " << bsp(a2 ,b2 ,c2 ,test3) << std::endl;
	std::cout << "test 9 " << bsp(a2 ,b2 ,c2 ,test5) << std::endl;
	return (0);
}