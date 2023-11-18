/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:23:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/18 11:09:18 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>
# include <algorithm>
# include <vector>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {
		
		}
		MutantStack(const MutantStack &obj) : std::stack<T, Container>(obj){

		}
		MutantStack	&operator=(const MutantStack &obj)
		{
			return (std::stack<T, Container>::operator=(obj));
		}
		~MutantStack() {
		
		}
		typedef typename Container::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

#endif
