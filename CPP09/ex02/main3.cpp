/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/05 18:26:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int cmpCount = 0;
int	debug = 0;

bool	compareLastElement(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
	++cmpCount;
	return (vec1.back() < vec2.back());
}

unsigned int	jacobsthalDiff(int index)
{
	int	diff[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922};
	if (index > 13)
		return (0);
	return (diff[index]);
}

void	updateIterators(std::vector<std::vector<std::vector<int> >::iterator>& mChain, std::vector<std::vector<int> >::iterator itPoint)
{
	std::vector<std::vector<std::vector<int> >::iterator>::iterator it;

	for (it = mChain.begin(); it != mChain.end();it++)
	{
		if (*it >= itPoint)
			(*it)++;
	}
}

std::vector<std::vector<int> >	sortAndInsert(std::vector<std::vector<int> > &mainChain, std::vector<std::vector<int> > &pend, std::vector<std::vector<std::vector<int> >::iterator> &vecOfIt)
{
	std::vector<std::vector<int> >::iterator	it;
	std::vector<std::vector<int> >::iterator	pendIt;
	std::vector<std::vector<std::vector<int> >::iterator>::iterator	vecItIt;
	size_t	index;
	size_t	i = 0;

	while (!pend.empty())
	{
		index = jacobsthalDiff(i);
		if (index > pend.size())
			index = pend.size();
		while (index > 0)
		{
			vecItIt = vecOfIt.begin() + index - 1;
			pendIt = pend.begin() + index - 1;
			it = std::lower_bound(mainChain.begin(), *vecItIt, *pendIt, compareLastElement);
			mainChain.insert(it, *pendIt);
			vecOfIt.erase(vecItIt);
			updateIterators(vecOfIt, it);
			pend.erase(pendIt);
			index--;
		}
		i++;
	}
	return (mainChain);
}

std::vector<std::vector<int> >	mergeNbr(std::vector<std::vector<int> >	vec)
{
	std::vector<std::vector<std::vector<int> >::iterator>	vectorOfIt;
	std::vector<std::vector<int> >							impairVec;
	std::vector<std::vector<int> >							pairedVec;
	std::vector<std::vector<int> >							depairedVec;
	std::vector<std::vector<int> >							mainChain;
	std::vector<std::vector<int> >							pend;

	if (vec.size() == 1)
		return (vec);
	if (vec.size() % 2)
	{
		impairVec.push_back(vec.back());
		vec.pop_back();
	}
	for(size_t i = 0; i < vec.size(); i += 2)
	{
		if (i + 1 < vec.size())
		{
			cmpCount++;
			if (vec[i].back() > vec[i + 1].back())
				std::swap(vec[i], vec[i + 1]);
			vec[i].insert(vec[i].end(), vec[i + 1].begin(), vec[i + 1].end());
			pairedVec.push_back(vec[i]);
		}
	}
	pairedVec = mergeNbr(pairedVec);
	for (size_t i = 0; i < pairedVec.size(); i++)
	{
		std::vector<int> left(pairedVec[i].begin(), pairedVec[i].begin() + (pairedVec[i].size() / 2));
		std::vector<int> right(pairedVec[i].begin() + (pairedVec[i].size() / 2), pairedVec[i].end());
		depairedVec.push_back(left);
		depairedVec.push_back(right);
	}
	int i = 1;
	mainChain.reserve(depairedVec.size() + 1);
	mainChain.push_back(depairedVec.front());
	for(std::vector<std::vector<int> >::iterator it = depairedVec.begin() + 1; it != depairedVec.end(); it++)
	{
		if (i % 2)
		{
			if (i != 1)
				vectorOfIt.push_back(mainChain.insert(mainChain.end(), *it));
			else
				mainChain.push_back(*it);
		}
		else
			pend.push_back(*it);
		i++;
	}
	if (!impairVec.empty())
	{
		pend.push_back(impairVec.back());
		vectorOfIt.push_back(mainChain.end());
	}
	if (pend.empty())
		return (depairedVec);
	mainChain = sortAndInsert(mainChain, pend, vectorOfIt);
	return (mainChain);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe obj(av);
		std::vector<std::vector<int> > vec;
		vec = mergeNbr(obj.getDoubleVec());
		size_t i = 0;
		std::cout << "Before:	";
		while (i < obj.getDoubleVec().size())
		{
			size_t j = 0;
			while (j < obj.getDoubleVec()[i].size())
			{
				std::cout << obj.getDoubleVec()[i][j++] << " ";
			}
			i++;
		}
		std::cout << std::endl;
		std::cout << "After:	";
		i = 0;
		while (i < vec.size())
		{
			size_t j = 0;
			while (j < vec[i].size())
			{
				std::cout << vec[i][j++] << " ";
			}
			i++;
		}
		std::cout << std::endl;
		std::cout << "Number of comparisions is: " << cmpCount << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
