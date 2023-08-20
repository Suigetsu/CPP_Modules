/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:05:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/20 16:55:52 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap C" << std::endl;
	this->HP = 100;
	this->NP = 50;
	this->AD = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Name ScavTrap C" << std::endl;
	this->HP = 100;
	this->NP = 50;
	this->AD = 20;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy ScavTrap C" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "Copy assignement ScavTrap operator" << std::endl;
	ClapTrap::operator=(obj);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap D" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->HP || !this->NP)
	{
		std::cout << "ScavTrap " << this->name << " cannot perform this task." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
	this->NP -= 1;
}

void	ScavTrap::guardGate()
{
	if (!this->HP || !this->NP)
	{
		std::cout << "ScavTrap " << this->name << " cannot perform this task." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
	this->NP -= 1;
}
