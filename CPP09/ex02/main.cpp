/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainlast.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:08:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/07 11:22:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	try
	{
		std::clock_t start = std::clock();
		double duration;
		vectorOfVector vec = PmergeMe::storeData<vectorOfVector, std::vector<int> >(av);
		std::cout << "Before:	";
		PmergeMe::printContainer<vectorOfVector, std::vector<int> >(vec);
		vec = PmergeMe::mergeNbr(vec);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		std::cout << "After:	";
		PmergeMe::printContainer<vectorOfVector, std::vector<int> >(vec);
		std::cout << "Time to process a range of " << vec.size() << " with std::vector: " << duration << " us" << std::endl;
		std::cout << std::endl;

		start = std::clock();
		listOfList lst = PmergeMe::storeData<listOfList, std::list<int> >(av);
		std::cout << "Before:	";
		PmergeMe::printContainer<listOfList, std::list<int> >(lst);
		lst = PmergeMe::mergeList(lst);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		std::cout << "After:	";
		PmergeMe::printContainer<listOfList, std::list<int> >(lst);
		std::cout << "Time to process a range of " << vec.size() << " with std::list: " << duration << " us" << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
}
