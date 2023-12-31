/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:17:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/09 15:56:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "This zombie has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed!" << std::endl;
}

void    Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void	Zombie::setZombie(std::string name)
{
	this->name = name;
}

std::string	Zombie::getZombie()
{
	return (this->name);
}
