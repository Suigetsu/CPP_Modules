/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/27 11:38:48 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->type = "cure";
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{

}

Cure::Cure(std::string const & type) : AMateria(type)
{
	
}

Cure	&Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		AMateria::operator=(obj);
	return (*this);
}

Cure::~Cure()
{
	
}

AMateria	*Cure::clone() const
{
	AMateria *materia = new Cure();
	return (materia);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
