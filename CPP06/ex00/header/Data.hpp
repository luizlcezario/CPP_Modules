/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:25:22 by llima-ce          #+#    #+#             */
/*   Updated: 2023/03/08 15:50:41 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>
# include <string>

using std::string;

typedef enum {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INV
} e_type;

class Data {
	private:
		string	_literals;
		e_type		_type;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		void		_convertType();

	public:
		Data();
		explicit Data(string literals);
		Data(Data const &src);
		~Data();
		
		Data &operator=(Data const &rhs);

		string		getLiterals() const;
		e_type		getType() const;
		operator	char();
		operator	int();
		operator	float();
		operator	double();
		void		setLiterals(string literals);
		static e_type	findType(string literals);
};

std::ostream &operator<<(std::ostream &o, Data const &rhs);


#endif