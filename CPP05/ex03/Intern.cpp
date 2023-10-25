/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:15:21 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/25 13:11:31 by mlagrini         ###   ########.fr       */
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

AForm	*createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm		*(*formArray[3])(std::string target) = {&createShrubbery, &createRobotomy, &createPresidential};
	int			i = 0;
	std::string	namesArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	while (i < 3)
	{
		if (formName == namesArray[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((*formArray[i])(target));
		}
		i++;
	}
	throw(AForm::UnknownFormName());
	return (NULL);
}
