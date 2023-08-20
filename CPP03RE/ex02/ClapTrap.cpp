/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:48:10 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/20 16:02:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("unknown"), HP(10), NP(10), AD(0)
{
	std::cout << "Default ClapTrap C" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HP(10), NP(10), AD(0)
{
	std::cout << "Name ClapTrap C" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy ClapTrap C" << std::endl;
	*this = obj;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignement ClapTrap operator" << std::endl;
	if (this != &obj)
	{
		this->name = obj.name;
		this->AD = obj.AD;
		this->HP = obj.HP;
		this->NP = obj.NP;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap D" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->HP || !this->NP)
	{
		std::cout << "ClapTrap " << this->name << " cannot perform this task." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AD << " points of damage!" << std::endl;
	this->NP -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->HP)
	{
		std::cout << "Stop, stop! ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	if (amount > this->HP)
		this->HP = 0;
	else
		this->HP -= amount;
	std::cout << "ClapTrap " << this->name << " took damage of " << amount << ", leaving him with " << this->HP << "HP" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->NP || !this->HP)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is repairing their Hit Points. The new Hit Points is " << this->HP + amount << "HP!" << std::endl;
	this->HP += amount;
	this->NP -= 1;	
}

void	ClapTrap::showStats()
{
	std::cout << "Name=" << this->name << " HP=" << this->HP << " NP=" << this->NP << " AD=" << this->AD << std::endl;
}
