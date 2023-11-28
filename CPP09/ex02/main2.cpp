/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/28 17:06:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int cmpCount = 0;

bool	compareLastElement(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
    return vec1.back() < vec2.back();
}

std::vector<std::vector<int> >	sorted(std::vector<std::vector<int> > &vec1, std::vector<std::vector<int> > &vec2)
{
	std::vector<std::vector<int> > result;
	std::vector<std::vector<int> >::iterator it;
	size_t i = 0;
	
	while (i < vec2.size())
	{
		it = std::lower_bound(vec1.begin(), vec1.end(), vec2[i], compareLastElement);
		vec1.insert(it, vec2[i]);
		i++;
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
	while (i < depairedVec.size())
	{
		if (i % 2)
			mainChain.push_back(depairedVec[i]);
		else
			pend.push_back(depairedVec[i]);
		i++;
	}
	if (!impairVec.empty())
		pend.push_back(impairVec.front());
	final = sorted(mainChain, pend);
	return (final);
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
		while (i < vec.size())
		{
			size_t j = 0;
			while (j < vec[i].size())
			{
				std::cout << vec[i][j++] << " ";
			}
			std::cout << std::endl;
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
