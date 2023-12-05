/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/01 15:51:57 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char	*PmergeMe::errorException::what() const throw()
{
	return ("Error");
}

PmergeMe::PmergeMe()
{	
}

PmergeMe::PmergeMe(char **args)
{
	int	i = 1;
	
	while (args[i])
	{
		std::istringstream iss(args[i]);
		int	num;
		while (iss >> num || !iss.eof())
		{
			if (iss.fail() || num < 0)
				throw (errorException());
			std::vector<int> arr;
			arr.push_back(num);
			this->lstSequence.push_back(num);
			this->vec.push_back(arr);
		}
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->vecSequence = obj.vecSequence;
		this->lstSequence = obj.lstSequence;
		this->vecIterator = obj.vecIterator;
		this->lstIterator = obj.lstIterator;
		this->vec = obj.vec;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	
}

std::vector<int>	&PmergeMe::getVector()
{
	return (this->vecSequence);
}

std::vector<std::vector<int> >	&PmergeMe::getDoubleVec()
{
	return (this->vec);
}
