/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:03:06 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/10 11:51:30 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &obj) : name(name), weaponA(obj)
{
	
}

HumanA::~HumanA()
{
	
}
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weaponA.getType() << std::endl;
}
