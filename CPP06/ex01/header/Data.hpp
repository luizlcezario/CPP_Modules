/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:18:04 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/15 23:55:37 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data
{
private:
	std::string _name;
	int _len;
	int _height;
	
public:
	Data();
	Data(std::string name, int len, int height);
	~Data();
	Data(Data const &src);
	Data &operator=(Data const &rhs);
	std::string getName();
	int getLen();
	int getHeight();
	void setLen(int len);
	void setHeight(int height);
	void setName(std::string name);
	double calcIMC();
};



#endif