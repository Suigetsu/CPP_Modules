/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/27 12:43:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int cmpCount = 0;

bool compareLastElement(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    return vec1.back() < vec2.back();
}

std::vector<std::vector<int> > sorted(std::vector<std::vector<int> > &vec1, std::vector<std::vector<int> > &vec2)
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


std::vector<std::vector<int> >	mergeall(std::vector<std::vector<int> > &vec1, std::vector<std::vector<int> > &vec2)
{
	std::vector<std::vector<int> > result;
	size_t i = 0;
	
	if (vec1.back().back() > vec2.back().back())
	{
		while (i < vec2.size())
			result.push_back(vec2[i++]);
		i = 0;
		while (i  < vec1.size())
			result.push_back(vec1[i++]);
		return (result);
	}
	while (i < vec1.size())
		result.push_back(vec1[i++]);
	i = 0;
	while (i  < vec2.size())
		result.push_back(vec2[i++]);
	return (result);
}

std::vector<std::vector<int> >	mergeNbr(std::vector<std::vector<int> > &vec)
{
	std::vector<std::vector<int> >	straggler;
	
	if (vec.size() <= 1)
		return (vec);
	if (vec.size() % 2)
	{
		straggler.push_back(vec.back());
		vec.pop_back();
	}
	// std::vector<std::vector<int> > final;
	std::vector<std::vector<int> > vec2;
	size_t j = 0;
	for (size_t i = 0; i < vec.size(); i += 2) {
        // If there are at least two vectors left to merge
        if (i + 1 < vec.size())
		{
            if (vec[i].back() > vec[i + 1].back())
			{
                std::swap(vec[i], vec[i + 1]);
            }
			vec2.push_back(vec[i]);
			vec2[j].insert(vec2[j].end(), vec[i + 1].begin(), vec[i + 1].end());
            // vec[i].insert(vec[i].end(), vec[i + 1].begin(), vec[i + 1].end());
            // vec.erase(vec.begin() + (i + 1));
			// i -= 1;
			j++;
        }
    }
	// size_t i = 0;
	// while (i < vec2.size())
	// {
	// 	size_t j = 0;
	// 	while (j < vec2[i].size())
	// 	{
	// 		std::cout << vec2[i][j++] << " ";
	// 	}
	// 	std::cout << std::endl;
	// 	i++;
	// }
	// std::cout << "================" << std::endl;
	mergeNbr(vec2);

	std::vector<std::vector<int> > res;
	std::vector<std::vector<int> > pend;
	res.push_back(vec2[0]);
	for (size_t i = 1; i < vec2.size(); i++)
	{
		if (i % 2)
			res.push_back(vec2[i]);
		else
			pend.push_back(vec2[i]);
	}
	size_t i = 0;
	while (i < res.size())
	{
		size_t j = 0;
		while (j < res[i].size())
		{
			std::cout << res[i][j++] << " ";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << "================" << std::endl;
	if (!straggler.empty())
		pend.push_back(straggler.front());
	if (res.empty() || pend.empty())
		return (vec2);
	std::vector<std::vector<int> >	final;
	final = sorted(res, pend);
	return (final);
}

// std::vector<std::vector<int> >	mergeNbr(std::vector<std::vector<int> > &vec)
// {
// 	std::vector<std::vector<int> >	straggler;
	
// 	if (vec.size() <= 1)
// 		return (vec);
// 	if (vec.size() % 2)
// 	{
// 		straggler.push_back(vec.back());
// 		vec.pop_back();
// 	}
// 	std::vector<std::vector<int> > left(vec.begin(), vec.begin() + (vec.size() / 2));
// 	std::vector<std::vector<int> > right(vec.begin() + (vec.size() / 2), vec.end());
// 	left = mergeNbr(left);
// 	right = mergeNbr(right);
// 	vec = mergeall(left, right);
// 	std::vector<std::vector<int> > res;
// 	std::vector<std::vector<int> > pend;

// 	res.push_back(vec[0]);
// 	res.push_back(vec[1]);
// 	for (size_t i = 2; i < vec.size(); i++)
// 	{
// 		if (i % 2)
// 			res.push_back(vec[i]);
// 		else
// 			pend.push_back(vec[i]);
// 	}
// 	if (!straggler.empty())
// 		pend.push_back(straggler.front());
// 	if (res.empty() || pend.empty())
// 		return (vec);
// 	std::vector<std::vector<int> >	final;
// 	final = sorted(res, pend);
// 	return (final);
// }

// std::vector<std::vector<int> >	mergeNbrs(std::vector<std::vector<int> > doubleVec, std::vector<int> vec, int size)
// {
// 	if (size == 1)
// 		return (doubleVec);
// 	int i = 0;
// 	while (i < size / 2)
// 	{
// 		int j = 0;
// 		while (j < size)
// 		{
// 			doubleVec[i][j] = vec[j];
// 			j++;
// 		}
// 	}
// }

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
