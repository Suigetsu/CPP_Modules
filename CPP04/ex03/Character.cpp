/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:59:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/27 22:14:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	int	i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		this->floor[i] = NULL;
		i++;
	}
	this->name = "no name";
}

Character::Character(const std::string &name)
{
	int	i = 0;
	while (i < 4)
	{
		this->inventory[i] = NULL;
		this->floor[i] = NULL;
		i++;
	}
	this->name = name;
}

Character::Character(const Character &obj)
{
	int	i = 0;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		if (this->floor[i])
			delete this->floor[i];
		this->inventory[i] = obj.inventory[i]->clone();
		this->floor[i] = obj.floor[i]->clone();
		i++;
	}
	this->name = obj.name;
}

Character	&Character::operator=(const Character &obj)
{
	int	i = -1;
	if (this != &obj)
	{
		while (++i < 4)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (this->floor[i])
			delete this->floor[i];
			this->inventory[i] = obj.inventory[i]->clone();
			this->floor[i] = obj.floor[i]->clone();
		}
		this->name = obj.name;
	}
	return (*this);
}

Character::~Character()
{
	int	i = 0;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (this->floor[i])
			delete this->floor[i];
		i++;
	}
}

void	Character::equip(AMateria *m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (this->floor[i])
			delete this->floor[i];
		i++;
	}
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void	Character::unequip(int idx)
{
	int	i = 0;
	if (!(idx >= 0 && idx <= 3))
		return ;
	while (i < 4)
	{
		if (!this->floor[i])
		{
			this->floor[i] = this->inventory[idx];
			break ;
		}
		i++;
	}
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (!(idx >= 0 && idx <= 3) || !this->inventory[idx])
		return ;
	this->inventory[idx]->use(target);
}
