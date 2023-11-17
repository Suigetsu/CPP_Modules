/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:16:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/17 17:41:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char *Span::MaxElementStoredException::what() const throw()
{
	return ("Exception: All the elements are stored.");
}

const char *Span::NoSpanFoundException::what() const throw()
{
	return ("Exception: No span can be found.");
}

Span::Span() : N(0){
	
}

Span::Span(unsigned int maxN){
	this->N = maxN;
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span	&Span::operator=(const Span &obj)
{
	if (this != &obj)
		this->N = obj.N;
	return (*this);
}

Span::~Span()
{
	
}

void	Span::addNumber(int nbr)
{
	if (this->vec.size() >= this->N)
		throw (MaxElementStoredException());
	this->vec.push_back(nbr);
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>::iterator it;
	unsigned int	shortSpan;
	
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw(NoSpanFoundException());
	std::sort(this->vec.begin(), this->vec.end());
	it = this->vec.begin();
	shortSpan = *(it + 1) - *it;
	while (it != this->vec.end() - 1)
	{
		shortSpan = std::min(shortSpan, static_cast<unsigned int>(*(it + 1) - *it));
		it++;
	}
	return (shortSpan);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>::iterator minIter;
	std::vector<int>::iterator maxIter;
	
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw(NoSpanFoundException());
	minIter = std::min_element(this->vec.begin(), this->vec.end());
	maxIter = std::max_element(this->vec.begin(), this->vec.end());
	return (*maxIter - *minIter);
}

void	Span::addNumberRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	// std::vector<int>::iterator it = begin;

	if (static_cast<unsigned int>(std::distance(begin, end)) > (this->N - this->vec.size()))
		throw (MaxElementStoredException());
	std::copy(begin, end, std::back_inserter(this->vec));
	// while (it != end)
	// {
	// 	addNumber(*it);
	// 	it++;
	// }
}
