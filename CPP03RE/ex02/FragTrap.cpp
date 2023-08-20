/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:29:17 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/20 16:55:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap C" << std::endl;
	this->HP = 100;
	this->NP = 100;
	this->AD = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Name FragTrap C" << std::endl;
	this->HP = 100;
	this->NP = 100;
	this->AD = 30;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy FragTrap C" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &obj)
{
	std::cout << "Copy assignement FragTrap operator" << std::endl;
	ClapTrap::operator=(obj);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap D" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (!this->NP || !this->HP)
	{
		std::cout << "FragTrap " << this->name << " cannot perform this task." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " is highFiving. High five back!" << std::endl;
	this->NP -= 1;
}
