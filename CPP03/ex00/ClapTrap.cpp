/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:02:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/16 19:07:31 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "The objects has been constructed" << std::endl;
	this->name = "N/A";
	this->HitPts = 10;
	this->NrgPts = 10;
	this->Ad = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "The name has ben initialized" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "The copy constructor has been called" << std::endl;
	*this = operator=(obj);
}

ClapTrap	&ClapTrap::operator=( const ClapTrap &obj )
{
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
