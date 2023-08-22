/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:49:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/22 18:03:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor" << std::endl;
}

Cat	&Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignemet copy operator" << std::endl;
	if (this != &obj)
		Animal::operator=(obj);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}

void	Cat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
