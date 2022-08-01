/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:06:26 by llima-ce          #+#    #+#             */
/*   Updated: 2022/08/01 00:09:24 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string	replacing( std::string &str, std::string &s1, std::string &s2,
						size_t pos ) {
	std::string strReplaced;

	if (str.empty() || s1.empty() || s2.empty())
		return (str);
	pos = str.find(s1, pos);
	strReplaced.substr(0, pos);
	strReplaced.append(s2);
	strReplaced.append(str.substr(pos + s1.length()));
	return (strReplaced);
}

std::string	replacingAll(std::string &str, std::string &s1, std::string &s2) {
	std::string	strReplaced;
	
	if (str.empty() || s1.empty() || s2.empty())
		return (str);
	strReplaced.assign(str);
	size_t pos = strReplaced.find(s1);
	while (pos !=  std::string::npos) {
		strReplaced = replacing(strReplaced, s1, s2, pos);
		pos = strReplaced.find(s1);
	}
	return (strReplaced);
}

