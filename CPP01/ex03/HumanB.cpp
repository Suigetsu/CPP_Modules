/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:03:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/10 12:06:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weaponB = nullptr;
}

HumanB::~HumanB()
{
	
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weaponB = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weaponB)
	{
		std::cout << this->name << " attacks with their " << this->weaponB->getType() << std::endl;
		return ;
	}
	std::cout << this->name << " doesn't have a weapon." << std::endl;
}
