/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/02 11:22:06 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int cmpCount = 0;

bool	compareLastElement(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
	++cmpCount;
    return vec1.back() < vec2.back();
}

unsigned int	jacobsthalDiff(int index)
{
	int	diff[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922};
	if (index > 13)
		return (0);
	return (diff[index]);
}


std::vector<std::vector<int> >	sorted(std::vector<std::vector<int> > &vec1, std::vector<std::vector<int> > &vec2, std::vector<int> indexVec)
{
	std::vector<std::vector<int> > result;
	std::vector<std::vector<int> >::iterator it;
	std::vector<std::vector<int> >::iterator vecIt;
	std::vector<std::vector<int> >::iterator it2;
	size_t k = 0;
	size_t i = 0;
	(void)indexVec;
	while (!vec2.empty())
	{
		size_t	index = jacobsthalDiff(k);
		if (index < vec2.size() && index != 0)
		{
			while (index > 0)
			{
				vecIt = vec2.begin() + (index - 1);
				if ((size_t)indexVec[index - 1] < vec1.size())
					it2 = vec1.begin() + indexVec[index - 1];
				else
					it2 = vec1.end();
				it = std::lower_bound(vec1.begin(), it2, *vecIt, compareLastElement);
				vec1.insert(it, *vecIt);
				vec2.erase(vecIt);
				indexVec.erase(indexVec.begin() + (index - 1));
				index--;
			}
		}
		else
		{
			vecIt = vec2.begin();
			if ((size_t)indexVec[i] < vec1.size())
				it2 = vec1.begin() + indexVec[i];
			else
				it2 = vec1.end();
			it = std::lower_bound(vec1.begin(), it2, *vecIt, compareLastElement);
			vec1.insert(it, *vecIt);
			vec2.erase(vecIt);
			i++;
		}
		k++;
	}
	return (vec1);
}

std::vector<std::vector<int> >	mergeNbr(std::vector<std::vector<int> > vec)
{
	std::vector<std::vector<int> >	impairVec;
	std::vector<std::vector<int> >	pairedVec;
	std::vector<std::vector<int> >	mainChain;
	std::vector<std::vector<int> >	pend;
	std::vector<std::vector<int> >	final;
	
	if (vec.size() <= 1)
		return (vec);
	if (vec.size() % 2)
	{
		impairVec.push_back(vec.back());
		vec.pop_back();
	}
	size_t i = 0;
	while (i < vec.size())
	{
		if (i + 1 < vec.size())
		{
			++cmpCount;
			if (vec[i].back() > vec[i + 1].back())
				std::swap(vec[i], vec[i + 1]);
			vec[i].insert(vec[i].end(), vec[i + 1].begin(), vec[i + 1].end());
			pairedVec.push_back(vec[i]);
		}
		i += 2;
	}
	pairedVec = mergeNbr(pairedVec);
	std::vector<std::vector<int> >	depairedVec;
	for (size_t i = 0; i < pairedVec.size(); i++)
	{
		std::vector<int>	left(pairedVec[i].begin(), pairedVec[i].begin() + (pairedVec[i].size() / 2));
		std::vector<int>	right(pairedVec[i].begin() + (pairedVec[i].size() / 2), pairedVec[i].end());
		depairedVec.push_back(left);
		depairedVec.push_back(right);
	}
	i = 1;
	mainChain.push_back(depairedVec.front());
	std::vector<int>	indexVec;
	while (i < depairedVec.size())
	{
		if (i % 2)
			mainChain.push_back(depairedVec[i]);
		else
		{
			indexVec.push_back(i);
			pend.push_back(depairedVec[i]);
		}
		i++;
	}
	if (!impairVec.empty())
	{
		indexVec.push_back(i);
		pend.push_back(impairVec.front());
	}
	final = sorted(mainChain, pend, indexVec);
	return (final);
}

std::list<std::list<int> >	mergeSortList(std::list<std::list<int> > lst)
{
	std::list<std::list<int> >	impairLst;
	std::list<std::list<int> >	pairedLst;
	std::list<std::list<int> >	mainChain;
	std::list<std::list<int> >	pend;
	std::list<std::list<int> >	final;
	std::list<std::list<int> >	depairedLst;

	if (lst.size() == 1)
		return (lst);
	if (lst.size() % 2)
	{
		impairLst.push_back(lst.back());
		lst.pop_back();
	}
	for (std::list<std::list<int> >::iterator it = lst.begin(); it != lst.end(); std::advance(it, 2))
	{
		std::list<std::list<int> >::iterator itNext = it;
		itNext++;
		if (itNext != lst.end())
		{
			if (it->back() > itNext->back())
				std::swap(it, itNext);
			it->insert(it->end(), itNext->begin(), itNext->end());
			pairedLst.push_back(*it);
		}
	}
	pairedLst = mergeSortList(pairedLst);
	for (std::list<std::list<int> >::iterator it = pairedLst.begin(); it != pairedLst.end(); it++)
	{
		size_t count = 0;
		std::list<int>	left;
		std::list<int>	right;

		while (count < it->size() / 2)
		{
			left.push_back(it);
		}
	}
	
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
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
