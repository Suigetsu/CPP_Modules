/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:08:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/28 14:09:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::vector<int> >	mergeNbr(std::vector<std::vector<int> > vec, int flag)
{
	
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
		vec = mergeNbr(obj.getDoubleVec(), 1);
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