/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:46:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/25 16:57:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	name;
		bool	indicator;
		const int	SignGrade;
		const int	ExecGrade;
	public:
		Form();
		Form(const std::string name, const int SignGrade, const int ExecGrade);
		Form(const Form &obj);
		~Form();
		Form	&operator=(const Form &obj);
		std::string	getName() const;
		bool	getIndicator() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		void	beSigned(Bureaucrat &obj);
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
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);

#endif
