/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:30:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/27 17:41:21 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Dog* a = new Dog();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* copy(a);
	const Animal* op = new Cat();
	
	std::cout << std::endl;
	op->makeSound();
	op = copy;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	copy->makeSound();
	op->makeSound();
	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	// delete copy;
	delete op;

	return 0;
}
