/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:46:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/21 14:52:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("N/A"), indicator(false), SignGrade(1), ExecGrade(1)
{
	
}
Form::Form(const std::string name, const int SignGrade, const int ExecGrade) : name(name), indicator(false), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	if (this->SignGrade < 1 || this->ExecGrade < 1)
		throw (GradeTooHighException());
	else if (this->SignGrade > 150 || this->ExecGrade > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &obj) : name(obj.getName()), SignGrade(obj.getSignGrade()), ExecGrade(obj.getExecGrade())
{
	
}

Form	&Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->indicator = obj.getIndicator();
	return (*this);
}

Form::~Form()
{
	
}

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIndicator() const
{
	return (this->indicator);
}

int	Form::getSignGrade() const
{
	return (this->SignGrade);
}

int	Form::getExecGrade() const
{
	return (this->ExecGrade);
}

std::ostream	&operator<<(std::ostream &out, const Form &obj)
{
	out << "From informations:\nName: " << obj.getName() << ".\n" << "Form signed(1) or not(0): " 
	<< obj.getIndicator() << ".\n" << "Grade required to sign: " << obj.getSignGrade()
	<< ".\n" << "Grade required to execute: " << obj.getExecGrade() << ".";
	return (out);
}

void	Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > this->SignGrade)
	{
		throw (GradeTooLowException());
		return ;
	}
	this->indicator = true;
}
