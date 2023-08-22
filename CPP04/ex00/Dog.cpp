/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:29:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/22 18:03:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor" << std::endl;
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignemet copy operator" << std::endl;
	if (this != &obj)
		Animal::operator=(obj);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
