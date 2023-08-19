/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:02:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 11:15:06 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor has been called" << std::endl;
	this->name = "N/A";
	this->HitPts = 100;
	this->NrgPts = 50;
	this->Ad = 20;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap name has been initialized" << std::endl;
	this->name = name;
	this->HitPts = 100;
	this->NrgPts = 50;
	this->Ad = 20;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor has been called" << std::endl;
	*this = obj;
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &obj )
{
	std::cout << "ClapTrap copy assignement operator is here!" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->HitPts = obj.HitPts;
		this->NrgPts = obj.NrgPts;
		this->Ad = obj.Ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap objects has been destroyed" << std::endl;
}

void		ClapTrap::attack( const std::string &target )
{
	if (!this->NrgPts || !this->HitPts)
	{
		std::cout << "ClapTrap " << this->name << " cannot perform this task." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->Ad << " points of damage!" << std::endl;
	this->NrgPts -= 1;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (!this->HitPts)
	{
		std::cout << "Stop, stop! ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " took damage of " << amount << ", leaving him with " << this->HitPts - amount << "HP" << std::endl;
	this->HitPts -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (!this->NrgPts || !this->HitPts)
	{
		std::cout << "ClapTrap " << this->name << " cannot be repaired!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is repairing their Hit Points. The new Hit Points is " << this->HitPts + amount << "HP!" << std::endl;
	this->HitPts += amount;
	this->NrgPts -= 1;	
}
