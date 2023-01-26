/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:08:00 by llima-ce          #+#    #+#             */
/*   Updated: 2023/01/26 13:21:47 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		explicit Cure(std::string const &type);
		Cure(Cure const &src);
		virtual ~Cure();
		
		Cure &operator=(Cure const &rhs);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif