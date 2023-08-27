/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/26 19:34:40 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const & type);
		Cure(const Cure &obj);
		~Cure();
		Cure		&operator=(const Cure &obj);
		AMateria	*clone() const;
		void		 use(ICharacter& target);
};

#endif
