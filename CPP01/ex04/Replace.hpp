/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:04:29 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 00:08:59 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>


std::string	replacing( std::string &str, std::string &s1, std::string &s2,
		size_t pos );
	
std::string	replacingAll(std::string &str, std::string &s1, std::string &s2);

#endif