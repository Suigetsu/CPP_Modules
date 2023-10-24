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
#include "Intern.hpp"

int	main()
{
	Intern	a;
	AForm	*form;
	Bureaucrat	b("chihaja", 5);
	form = a.makeForm("shrubbery creation", "test");
	b.signForm(*form);
	b.executeForm(*form);
	delete form;
	// Bureaucrat	a("B name", 26);
	// PresidentialPardonForm	form("cool form");
	// RobotomyRequestForm	form2("another cool form");
	// ShrubberyCreationForm	form3("the coolest form ever");

	// a.signForm(form);
	// a.executeForm(form);
	// a.signForm(form2);
	// a.executeForm(form2);
	// a.signForm(form3);
	// a.executeForm(form3);
}
