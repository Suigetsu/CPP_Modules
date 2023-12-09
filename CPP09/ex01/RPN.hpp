/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:38:17 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/09 11:16:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <iterator>
# include <cctype>
# include <sstream>

class	errorException : public std::exception
{
	public:
		const char *what() const throw();
};

class	RPN
{
	private:
		RPN();
		RPN(std::string expression);
		RPN(const RPN &obj);
		RPN	&operator=(const RPN &obj);
	public:
		~RPN();
		static int	calculateRPN(std::string expression);
};

#endif
