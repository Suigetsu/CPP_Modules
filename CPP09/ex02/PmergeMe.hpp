/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/25 10:19:15 by mlagrini         ###   ########.fr       */
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

class	PmergeMe
{
	private:
		std::vector<std::vector<int> >	vec;
		std::vector<int>			vecSequence;
		std::list<int>				lstSequence;
		std::vector<int>::iterator	vecIterator;
		std::list<int>::iterator	lstIterator;
	public:
		PmergeMe();
		PmergeMe(char **args);
		PmergeMe(const PmergeMe &obj);
		PmergeMe	&operator=(const PmergeMe &obj);
		~PmergeMe();
		class	errorException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		std::vector<int>				&getVector();
		std::vector<std::vector<int> >	&getDoubleVec();
};

#endif
