/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:01:33 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 11:51:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor is here!" << std::endl;
	this->HitPts = 100;
	this->NrgPts = 50;
	this->Ad = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "Name constructor of ScavTrap is here" << std::endl;
	this->HitPts = 100;
	this->NrgPts = 50;
	this->Ad = 20;
}

ScavTrap::ScavTrap( const ScavTrap &obj ) : ClapTrap( obj )
{
	std::cout << "ScavTrap copy constructor." << std::endl;
}

ScavTrap	&ScavTrap::operator=( const ScavTrap &obj )
{
	std::cout << "ScavTrap copy assignement operator is here!" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->HitPts = obj.HitPts;
		this->NrgPts = obj.NrgPts;
		this->Ad = obj.Ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap is out." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (!this->NrgPts || !this->HitPts)
	{
		std::cout << "ScavTrap can't do anything." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " is in keeper mode" << std::endl;
}
