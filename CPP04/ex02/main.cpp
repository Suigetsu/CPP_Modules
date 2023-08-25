/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:30:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/25 18:10:35 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* k = NULL;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* a(j);
	std::cout << a->getType() << std::endl;
	a->makeSound();
	// b->makeSound();
	k->makeSound();
	delete j;//should not create a leak
	delete i;
	
	// delete a;
	return 0;
}
