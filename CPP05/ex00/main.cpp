/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:15:02 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/06 18:15:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	test("Med", 20), a("random", 1), b("exception", 150), c("high", 0), d("low", 151);


	--test;
	std::cout << test << std::endl;
	++test;
	std::cout << test << std::endl;

	std::cout << "<><><><><><><><><><>" << std::endl << std::endl;
	--a;
	std::cout << a << std::endl;
	++a;
	std::cout << a << std::endl;

	std::cout << "<><><><><><><><><><>" << std::endl << std::endl;
	--b;
	std::cout << b << std::endl;
	++b;
	std::cout << b << std::endl;


	--c;
	std::cout << c << std::endl;
	++c;
	std::cout << c << std::endl;


	--d;
	std::cout << d << std::endl;
	++d;
	std::cout << d << std::endl;
}
