/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:55:49 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/16 17:11:18 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <iterator>

class NoOccurrencFoundException : public std::exception
{
	public:
		const char *what() const throw(){
			return ("No occurrence is found.");
		}
};

template <typename T>
void	easyFind(T first, int occurrence)
{
	typename T::iterator vecIt;
	
	vecIt = std::find(first.begin(), first.end(), occurrence);
	if (vecIt != first.end())
	{
		std::cout << "The occurrence " << occurrence << " has been found!" << std::endl;
		return ;
	}
	throw(NoOccurrencFoundException());
}

#endif
