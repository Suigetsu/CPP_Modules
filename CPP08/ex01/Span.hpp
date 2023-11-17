/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:16:44 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/17 15:23:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>
# include <list>

class	Span
{
	private:
		unsigned int	N;
		std::vector<int> vec;
	public:
		Span();
		Span(unsigned int maxN);
		Span(const Span &obj);
		Span	&operator=(const Span &obj);
		~Span();
		void	addNumber(int nbr);
		void	addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		class	MaxElementStoredException : public std::exception{
			public:
				const char *what() const throw();
		};
		class	NoSpanFoundException : public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif
