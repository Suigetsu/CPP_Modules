/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:46:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/23 09:59:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("N/A"), indicator(false), SignGrade(1), ExecGrade(1)
{
	
}
AForm::AForm(const std::string name, const int SignGrade, const int ExecGrade) : name(name), indicator(false), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
	if (this->SignGrade < 1 || this->ExecGrade < 1)
		throw (GradeTooHighException());
	else if (this->SignGrade > 150 || this->ExecGrade > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &obj) : name(obj.getName()), SignGrade(obj.getSignGrade()), ExecGrade(obj.getExecGrade())
{
	
}

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->indicator = obj.getIndicator();
	return (*this);
}

AForm::~AForm()
{
	
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIndicator() const
{
	return (this->indicator);
}

int	AForm::getSignGrade() const
{
	return (this->SignGrade);
}

int	AForm::getExecGrade() const
{
	return (this->ExecGrade);
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	out << "From informations:\nName: " << obj.getName() << ".\n" << "Form signed(1) or not(0): " 
	<< obj.getIndicator() << ".\n" << "Grade required to sign: " << obj.getSignGrade()
	<< ".\n" << "Grade required to execute: " << obj.getExecGrade() << ".";
	return (out);
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > this->SignGrade)
	{
		throw (GradeTooLowException());
		return ;
	}
	this->indicator = true;
}

void	AForm::isExecuted(const Bureaucrat &obj) const
{
	if (!this->getIndicator())
		throw(NotSignedException());
	if (obj.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
}
