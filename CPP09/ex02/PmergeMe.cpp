/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/09 11:17:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char	*PmergeMe::errorException::what() const throw()
{
	return ("Error");
}

unsigned int	jacobsthalDiff(int index)
{
	int	diff[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922};
	if (index > 13)
		return (0);
	return (diff[index]);
}

void	updateIterators(std::vector<vectorOfVector::iterator>& mChain, vectorOfVector::iterator itPoint)
{
	std::vector<vectorOfVector::iterator>::iterator it;

	for (it = mChain.begin(); it != mChain.end();it++)
	{
		if (*it >= itPoint)
			(*it)++;
	}
}

vectorOfVector	sortAndInsert(vectorOfVector &mainChain, vectorOfVector &pend, std::vector<vectorOfVector::iterator> &vecOfIt)
{
	vectorOfVector::iterator	it;
	vectorOfVector::iterator	pendIt;
	std::vector<vectorOfVector::iterator>::iterator	vecItIt;
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
			it = std::lower_bound(mainChain.begin(), *vecItIt, *pendIt, PmergeMe::compareLastElement<std::vector<int> >);
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

vectorOfVector	PmergeMe::mergeNbr(vectorOfVector vec)
{
	std::vector<vectorOfVector::iterator> vectorOfIt;
	vectorOfVector impairVec;
	vectorOfVector pairedVec;
	vectorOfVector depairedVec;
	vectorOfVector mainChain;
	vectorOfVector pend;

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
	for(vectorOfVector::iterator it = depairedVec.begin() + 1; it != depairedVec.end(); it++)
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

listOfList	sortAndInsertList(listOfList &mainChain, listOfList &pend, std::list<listOfList::iterator> &listOfIt)
{
	listOfList::iterator	it;
	listOfList::iterator	pendIt;
	std::list<listOfList::iterator>::iterator	listItIt;
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
			it = std::lower_bound(mainChain.begin(), *listItIt, *pendIt, PmergeMe::compareLastElement<std::list<int> >);
			mainChain.insert(it, *pendIt);
			listOfIt.erase(listItIt);
			pend.erase(pendIt);
			index--;
		}
		i++;
	}
	return (mainChain);
}

listOfList	PmergeMe::mergeList(listOfList lst)
{
	std::list<listOfList::iterator>	listOfIt;
	listOfList						impairLst;
	listOfList						pairedLst;
	listOfList						depairedLst;
	listOfList						mainChain;
	listOfList						pend;
	listOfList::iterator 			itNext = lst.begin();

	if (lst.size() == 1)
		return (lst);
	if (lst.size() % 2)
	{
		impairLst.push_back(lst.back());
		lst.pop_back();
	}
	for (listOfList::iterator it = lst.begin(); it != lst.end(); std::advance(it, 2))
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
	listOfList::iterator outerIt = pairedLst.begin();
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

PmergeMe::~PmergeMe()
{
	
}
