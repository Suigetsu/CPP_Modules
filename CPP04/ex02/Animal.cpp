/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:02:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/25 17:26:34 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("notype")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = obj;
}

Animal	&Animal::operator=(const Animal &obj)
{
	std::cout << "Animal assignemet copy operator" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

// std::string	Animal::getType() const
// {
// 	return (this->type);
// }

