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

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		void		GradeTooHighException(int grade);
		void		GradeTooLowException(int grade);
		Bureaucrat	&operator++();
		Bureaucrat	&operator--();
		std::string	getName();
		int	getGrade();
};
std::ostream	&operator<<( std::ostream &out, Bureaucrat &b );

#endif
