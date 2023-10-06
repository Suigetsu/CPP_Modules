/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:49:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/03 16:49:56 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	GradeTooHighException(grade);
	GradeTooLowException(grade);
	this->grade = grade;
}

std::string Bureaucrat::getName()
{
	return (this->name);
}

int    Bureaucrat::getGrade()
{
	return (this->grade);
}

void	Bureaucrat::GradeTooLowException(int grade)
{
	try
	{
		if (grade > LOWEST_GRADE)
			throw(grade);
	}
	catch(int grade)
	{
		std::cout << "The grade is too low" << std::endl;
	}   
}

void	Bureaucrat::GradeTooHighException(int grade)
{
	try
	{
		if (grade < HIGHEST_GRADE)
			throw(grade);
	}
	catch(int grade)
	{
		std::cout << "The grade is too high" << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{

}

std::ostream	&operator<<( std::ostream &out, Bureaucrat &b )
{
	out << b.getName() << ", " << "bureaucrat grade " << b.getGrade();
	return (out);
}

Bureaucrat	&Bureaucrat::operator++()
{
	--this->grade;
	this->GradeTooLowException(this->grade);
	this->GradeTooHighException(this->grade);
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--()
{
	++this->grade;
	this->GradeTooLowException(this->grade);
	this->GradeTooHighException(this->grade);
	return (*this);
}
