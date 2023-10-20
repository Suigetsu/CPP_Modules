/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:56:30 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/17 15:56:30 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat def;
		std::cout << def << std::endl;
		def.DecrementGrade();
		std::cout << def << std::endl;
		def.IncrementGrade();
		def.IncrementGrade();
		std::cout << def << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*********************" << std::endl;
	try
	{
		Bureaucrat a("LOW", 1000);
		std::cout << a << std::endl;
		a.DecrementGrade();
		std::cout << a << std::endl;
		a.IncrementGrade();
		std::cout << a << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*********************" << std::endl;
	try
	{
		Bureaucrat a("HIGH", -1);
		std::cout << a << std::endl;
		a.DecrementGrade();
		std::cout << a << std::endl;
		a.IncrementGrade();
		std::cout << a << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
