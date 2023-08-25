/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:14:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/22 18:15:01 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat assignemet copy operator" << std::endl;
	if (this != &obj)
		WrongAnimal::operator=(obj);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (this->type);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
