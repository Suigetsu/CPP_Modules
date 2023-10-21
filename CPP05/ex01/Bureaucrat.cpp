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

Bureaucrat::Bureaucrat() : name("N/A"), grade(1)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{

	if (this->grade < 1)
		throw (GradeTooHighException());
	else if (this->grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
		this->grade = obj.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::IncrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw (GradeTooHighException());
	else if (this->grade > 150)
		throw (GradeTooLowException());
}

void	Bureaucrat::DecrementGrade()
{
	this->grade++;
	if (this->grade < 1)
		throw (GradeTooHighException());
	else if (this->grade > 150)
		throw (GradeTooLowException());
}

std::ostream	&operator<<( std::ostream &out, Bureaucrat &b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (out);
}

void	Bureaucrat::signForm(Bureaucrat &obj, Form &form)
{
	try
	{
		form.beSigned(obj);
		std::cout << obj.getName() << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << obj.getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
