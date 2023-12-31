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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	a("B name", 26);
		RobotomyRequestForm	form2("another cool form");

		a.executeForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat	a("B name", 26);
	PresidentialPardonForm	form("cool form");
	RobotomyRequestForm	form2("another cool form");
	ShrubberyCreationForm	form3("the coolest form ever");

	a.signForm(form);
	a.executeForm(form);
	a.signForm(form2);
	a.executeForm(form2);
	a.signForm(form3);
	a.executeForm(form3);
}
