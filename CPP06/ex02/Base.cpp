/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:49:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/01 13:45:12 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	
}

Base	*generate(void)
{	
	srand(time(0));
	if (rand() % 2)
		return (new A);
	else
	{
		if (rand() % 2)
			return (new C);
		else
			return (new B);
	}
	return (new Base);
}

void	identify(Base *p)
{
	A*	aPtr = dynamic_cast<A*>(p);
	B*	bPtr = dynamic_cast<B*>(p);
	C*	cPtr = dynamic_cast<C*>(p);

	if (aPtr)
		std::cout << "The actual type of the object pointed to by p is 'A'" << std::endl;
	else if (bPtr)
		std::cout << "The actual type of the object pointed to by p is 'B'" << std::endl;
	else if (cPtr)
		std::cout << "The actual type of the object pointed to by p is 'C'" << std::endl;
	else
		std::cout << "no type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &aRef = dynamic_cast<A&>(p);
		(void)aRef;
		std::cout << "The actual type of the object pointed to by p is 'A'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B &bRef = dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "The actual type of the object pointed to by p is 'B'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C &cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "The actual type of the object pointed to by p is 'C'" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "no type" << std::endl;
}
