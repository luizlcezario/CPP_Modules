/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:09:53 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 13:22:43 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"


class Ice : public AMateria {
	public:
		Ice(void);
		explicit Ice(std::string const &type);
		Ice(Ice const &src);
		virtual ~Ice(void);
		
		Ice &operator=(Ice const &rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif