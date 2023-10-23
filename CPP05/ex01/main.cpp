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
#include "Form.hpp"

int	main()
{
	Form	a("test", 10, 20);

	std::cout << a << std::endl;
	std::cout << "*********************" << std::endl;
	try
	{
		Form a("Form", 150, 0);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*********************" << std::endl;
	try
	{
		Form a("A form", 6, 10);
		Bureaucrat b("Someone", 3);
		b.signForm(a);
		std::cout << a << b << std::endl;
		b.IncrementGrade();
		b.IncrementGrade();
		std::cout << a << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*********************" << std::endl;
	try
	{
		Form a("A form", 2, 10);
		Bureaucrat b("Someone", 3);
		b.signForm(a);
		std::cout << a << b << std::endl;
		b.IncrementGrade();
		b.signForm(a);
		b.IncrementGrade();
		b.signForm(a);
		std::cout << a << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "*********************" << std::endl;
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
