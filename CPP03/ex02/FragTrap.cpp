/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:24 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 11:53:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor is here!" << std::endl;
	this->HitPts = 100;
	this->NrgPts = 100;
	this->Ad = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	std::cout << "Name constructor of FragTrap is here" << std::endl;
	this->HitPts = 100;
	this->NrgPts = 100;
	this->Ad = 30;
}

FragTrap::FragTrap( const FragTrap &obj ) : ClapTrap( obj )
{
	std::cout << "FragTrap copy constructor." << std::endl;
}

FragTrap	&FragTrap::operator=( const FragTrap &obj )
{
	std::cout << "FragTrap copy assignement operator is here!" << std::endl;
	if(this != &obj)
	{
		this->name = obj.name;
		this->HitPts = obj.HitPts;
		this->NrgPts = obj.NrgPts;
		this->Ad = obj.Ad;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap is out." << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (!this->NrgPts || !this->HitPts)
	{
		std::cout << "FragTrap can't do anything." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " is asking for high fives!" << std::endl;
}
