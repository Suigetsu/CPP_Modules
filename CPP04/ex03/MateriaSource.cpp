/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:01:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/27 12:13:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	int	i = 0;
	while (i < 4)
		this->inventory[i++] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	int	i = -1;
	while (++i < 4)
		this->inventory[i] = obj.inventory[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &obj)
{
	int	i = -1;
	if (this != &obj)
	{
		while (++i < 4)
		{
			delete this->inventory[i];
			this->inventory[i] = obj.inventory[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	int	i = 0;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		i++;
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m->clone();
			break ;
		}
		i++;
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;
	while (i < 4)
	{
		if (this->inventory[i] && type == this->inventory[i]->getType())
			return (this->inventory[i]->clone());
		i++;
	}
	return (0);
}
