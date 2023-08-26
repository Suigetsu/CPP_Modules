/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:29:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/26 15:20:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	this->type = "Dog";
	this->dogIdeas = new Brain;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->dogIdeas = new Brain(*obj.dogIdeas);
}

Dog	&Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignemet copy operator" << std::endl;
	if (this != &obj)
	{
		delete this->dogIdeas;
		this->dogIdeas = new Brain(*obj.dogIdeas);
		Animal::operator=(obj);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete this->dogIdeas;
}

std::string	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
