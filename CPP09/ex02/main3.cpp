/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/07 10:32:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int	debug = 0;

bool	compareLastElement(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
	++cmpCount;
	return (vec1.back() < vec2.back());
}

bool	compareLastElementList(const std::list<int>& lst1, const std::list<int>& lst2)
{
	++cmpCount;
	return (lst1.back() < lst2.back());
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

std::list<std::list<int> >	sortAndInsertList(std::list<std::list<int> > &mainChain, std::list<std::list<int> > &pend, std::list<std::list<std::list<int> >::iterator> &listOfIt)
{
	std::list<std::list<int> >::iterator	it;
	std::list<std::list<int> >::iterator	pendIt;
	std::list<std::list<std::list<int> >::iterator>::iterator	listItIt;
	size_t	index;
	size_t	i = 0;

	while (!pend.empty())
	{
		index = jacobsthalDiff(i);
		if (index > pend.size())
			index = pend.size();
		while (index > 0)
		{
			listItIt = listOfIt.begin();
			pendIt = pend.begin();
			std::advance(listItIt, index - 1);
			std::advance(pendIt, index - 1);
			it = std::lower_bound(mainChain.begin(), *listItIt, *pendIt, compareLastElementList);
			mainChain.insert(it, *pendIt);
			listOfIt.erase(listItIt);
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

std::list<std::list<int> >	mergeList(std::list<std::list<int> > lst)
{
	std::list<std::list<std::list<int> >::iterator>	listOfIt;
	std::list<std::list<int> >						impairLst;
	std::list<std::list<int> >						pairedLst;
	std::list<std::list<int> >						depairedLst;
	std::list<std::list<int> >						mainChain;
	std::list<std::list<int> >						pend;
	std::list<std::list<int> >::iterator 			itNext = lst.begin();

	if (lst.size() == 1)
		return (lst);
	if (lst.size() % 2)
	{
		impairLst.push_back(lst.back());
		lst.pop_back();
	}
	for (std::list<std::list<int> >::iterator it = lst.begin(); it != lst.end(); std::advance(it, 2))
	{
		itNext = it;
		itNext++;
		if (itNext != lst.end())
		{
			if (it->back() > itNext->back())
				std::swap(*it, *itNext);
			it->insert(it->end(), itNext->begin(), itNext->end());
			pairedLst.push_back(*it);
		}
	}
	pairedLst = mergeList(pairedLst);
	std::list<std::list<int> >::iterator outerIt = pairedLst.begin();
	for (size_t i = 0; i < pairedLst.size(); i++)
	{
		std::list<int>::iterator innerIt = outerIt->begin();
		std::list<int> left;
		std::list<int> right;
	
		for (size_t j = 0; j < outerIt->size() / 2; j++)
		{
			left.push_back(*innerIt);
			innerIt++;
		}
		for (size_t j = 0; j < outerIt->size() / 2; j++)
		{
			right.push_back(*innerIt);
			innerIt++;
		}
		depairedLst.push_back(left);
		depairedLst.push_back(right);
		outerIt++;
	}
	int i = 1;
	outerIt = depairedLst.begin();
	mainChain.push_back(*outerIt);
	outerIt++;
	for(; outerIt != depairedLst.end(); outerIt++)
	{
		if (i % 2)
		{
			if (i != 1)
				listOfIt.push_back(mainChain.insert(mainChain.end(), *outerIt));
			else
				mainChain.push_back(*outerIt);
		}
		else
			pend.push_back(*outerIt);
		i++;
	}
	if (!impairLst.empty())
	{
		pend.push_back(impairLst.back());
		listOfIt.push_back(mainChain.end());
	}
	if (pend.empty())
		return (depairedLst);
	mainChain = sortAndInsertList(mainChain, pend, listOfIt);
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
		std::clock_t start;
		double duration;
		start = std::clock();
		PmergeMe obj(av);
		std::vector<std::vector<int> > vec;
		std::list<std::list<int> > lst;
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
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		std::cout << std::endl;
		std::cout << "Time to processa range of " << vec.size() << " elements with std::vector: " << duration << " us" << std::endl;
		std::cout << std::endl;
		lst = mergeList(obj.getDoubleLst());
		std::cout << "Before:	";
		std::list<std::list<int> >::iterator outerIt = obj.getDoubleLst().begin();
		for (; outerIt != obj.getDoubleLst().end(); outerIt++)
		{
			for (std::list<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); innerIt++)
			{
				std::cout << *innerIt << " ";
			}
		}
		std::cout << std::endl;
		std::cout << "After:	";
		outerIt = lst.begin();
		for (; outerIt != lst.end(); outerIt++)
		{
			for (std::list<int>::iterator innerIt = outerIt->begin(); innerIt != outerIt->end(); innerIt++)
			{
				std::cout << *innerIt << " ";
			}
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
