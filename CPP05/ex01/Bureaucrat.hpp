/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:35:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/03 16:35:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

# include <iostream>
# include <exception>
# include "Form.hpp"

class	Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &obj);
		std::string	getName() const;
		int	getGrade() const;
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw() {
					return ("Grade is too high");
				}
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw() {
					return ("Grade is too low");
				}
		};
		void	IncrementGrade();
		void	DecrementGrade();
		void	signForm(Bureaucrat &obj, Form &form);
};
std::ostream	&operator<<( std::ostream &out, Bureaucrat &b );

#endif
