/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:06:49 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/16 17:14:31 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int>	v;
	std::deque<int>		dq;
	std::list<int>		lst;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	dq.push_front(2);
	dq.push_back(20);
	lst.push_front(110);
	lst.push_back(220);
	try
	{
		easyFind(v, 2);
		easyFind(v, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyFind(dq, 20);
		easyFind(dq, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyFind(lst, 220);
		easyFind(lst, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
