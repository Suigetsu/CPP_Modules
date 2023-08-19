/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:02:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 12:02:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "The default constructor has been called" << std::endl;
	this->name = "N/A";
	this->HitPts = 10;
	this->NrgPts = 10;
	this->Ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "The name has been initialized" << std::endl;
	this->name = name;
	this->HitPts = 10;
	this->NrgPts = 10;
	this->Ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "The copy constructor has been called" << std::endl;
	*this = operator=(obj);
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &obj )
{
	std::cout << "the copy assignement operator is here!" << std::endl;
	if(this == &obj)
		return (*this);
	this->name = obj.name;
	this->HitPts = obj.HitPts;
	this->NrgPts = obj.NrgPts;
	this->Ad = obj.Ad;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "The objects has been destroyed" << std::endl;
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
	if (amount > this->HitPts)
		this->HitPts = 0;
	else
		this->HitPts -= amount;
	std::cout << "ClapTrap " << this->name << " took damage of " << amount << ", leaving him with " << this->HitPts << "HP" << std::endl;
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
