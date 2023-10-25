/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:46:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/21 14:49:45 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	name;
		bool	indicator;
		const int	SignGrade;
		const int	ExecGrade;
	public:
		AForm();
		AForm(const std::string name, const int SignGrade, const int ExecGrade);
		AForm(const AForm &obj);
		virtual ~AForm();
		AForm	&operator=(const AForm &obj);
		std::string	getName() const;
		bool	getIndicator() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		void	beSigned(Bureaucrat &obj);
		void	isExecuted(const Bureaucrat &obj) const;
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw ()
				{
					return ("Form grade is too low");
				}
		};
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw ()
				{
					return ("Form grade is too High");
				}
		};
		class	NotSignedException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Form is not signed yet.");
				}
		};
		class	UnknownFormName : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Intern couldn't create the form.");
				}
		};
		virtual void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif
