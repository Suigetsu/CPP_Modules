/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:30:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/29 17:43:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *arr[10];
	
	int	index = 0;
	while (index < 5)
		arr[index++] = new Cat();
	while (index < 10)
		arr[index++] = new Dog();
	index = 0;
	while (index < 10)
		delete arr[index++];
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
