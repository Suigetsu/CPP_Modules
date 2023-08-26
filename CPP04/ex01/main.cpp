/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:30:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/26 15:16:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Dog* a = new Dog();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// i->makeSound();
	// j->makeSound();
	// delete j;//should not create a leak
	// delete i;
	
	Dog basic;
	{
		Dog tmp = basic;
		tmp.makeSound();
	}

	return 0;
}
