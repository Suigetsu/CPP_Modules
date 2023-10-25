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
	Bureaucrat	hafida("hafida", 1);
	try
	{
		Intern	a;
		AForm	*form;
		Bureaucrat	b("chihaja", 5);
		form = a.makeForm("shrubbery creatin", "test");
		b.signForm(*form);
		b.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		hafida.signForm(*rrf);
		rrf->execute(hafida);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		hafida.signForm(*rrf);
		rrf->execute(hafida);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
