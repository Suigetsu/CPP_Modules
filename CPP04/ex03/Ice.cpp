/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:31 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/26 19:35:50 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(std::string const & type) : AMateria(type)
{
	
}


Ice::Ice(const Ice &obj)
{
	this->type = obj.type;
}

Ice	&Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Ice::~Ice()
{
	
}

AMateria	*Ice::clone() const
{
	AMateria *materia = new Ice();
	return (materia);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
