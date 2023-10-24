/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:15:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/24 17:53:56 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern	&Intern::operator=(const Intern &obj)
{
	(void)obj;
	return (*this);
}

Intern::~Intern()
{
	
}

AForm	*Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm		*formArray[3] = {createShrubbery(target), createRobotomy(target), createPresidential(target)};
	int			i = 0;
	std::string	namesArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	while (i < 3)
	{
		if (formName == namesArray[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (formArray[i]);
		}
		i++;
	}
	std::cout << "Intern couldn't create " << formName << " because it doesn't exist." << std::endl;
	return (NULL);
}
