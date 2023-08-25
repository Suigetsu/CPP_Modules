/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:22:22 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/25 13:24:56 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	int	i = 0;
	std::cout << "Brain constructor" << std::endl;
	while (i < 100)
		this->ideas[i++] = "no idea";
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = obj;
}

Brain	&Brain::operator=(const Brain &obj)
{
	int	i = 0;
	std::cout << "Brain assignement copy operator" << std::endl;
	if (this != &obj)
	{
		while (i < 100)
		{
			this->ideas[i] = obj.ideas[i];
			i++;
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}
