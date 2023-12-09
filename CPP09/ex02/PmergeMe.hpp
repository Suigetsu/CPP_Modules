/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/07 13:02:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <iterator>
# include <algorithm>

typedef std::vector<std::vector<int> > vectorOfVector;
typedef std::list<std::list<int> > listOfList;

class	PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(char **args);
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
	public:
		~PmergeMe();
		class	errorException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		template <typename T, typename subT>
		static T	storeData(char **args)
		{
			T container;
			int	i = 1;
	
			while (args[i])
			{
				std::istringstream iss(args[i]);
				int	num;
				while (iss >> num || !iss.eof())
				{
					if (iss.fail() || num < 0)
						throw (errorException());
					subT arr;
					arr.push_back(num);
					container.push_back(arr);
				}
				i++;
			}
			return (container);
		}
		template <typename T>
		static bool	compareLastElement(const T& cont1, const T& cont2)
		{
			return (cont1.back() < cont2.back());
		}
		template <typename T, typename subT>
		static void	printContainer(T container)
		{
			typename T::iterator it;
			
			for (it = container.begin(); it != container.end(); it++)
			{
				for (typename subT::iterator itt = it->begin(); itt != it->end(); itt++)
				{
					std::cout << *itt << " ";
				}
			}
			std::cout << std::endl;
		}
		static vectorOfVector	mergeNbr(vectorOfVector vec);
		static listOfList		mergeList(listOfList lst);
};

#endif
