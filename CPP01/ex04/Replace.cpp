/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:06:26 by llima-ce          #+#    #+#             */
/*   Updated: 2023/02/27 22:09:27 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string	replacing( std::string &str, std::string &s1, std::string &s2,
						size_t pos ) {
	std::string tmp;

	if (str.empty() || s1.empty() || s2.empty())
		return (str);
	tmp = str.substr(0, pos);
	tmp.append(s2);
	tmp.append(str.substr(pos + s1.length()));
	return (tmp);
}

std::string	replacingAll(std::string &str, std::string &s1, std::string &s2) {
	std::string	strReplaced;
	
	if (str.empty() || s1.empty() || s2.empty())
		return (str);
	strReplaced = str;
	size_t pos = strReplaced.find(s1);
	while (pos !=  std::string::npos) {
		strReplaced = replacing(strReplaced, s1, s2, pos );
		pos = strReplaced.find(s1);
	}
	return (strReplaced);
}

