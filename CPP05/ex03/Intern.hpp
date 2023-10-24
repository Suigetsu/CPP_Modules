/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:15:16 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/24 17:53:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);
		~Intern();
		AForm	*makeForm(std::string formName, std::string target);
		AForm	*createRobotomy(std::string target);
		AForm	*createShrubbery(std::string target);
		AForm	*createPresidential(std::string target);
};

#endif
