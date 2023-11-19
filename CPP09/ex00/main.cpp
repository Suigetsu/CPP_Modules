/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/19 18:19:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	struct tm tm;
	std::string s("2024-01-01");
	std::string	str;
	std::fstream	file;
	std::map<std::string, BitcoinExchange> dataMap;
	
	
	if (ac != 2 || strncmp(&av[1][strlen(av[1]) - 4], ".csv", 4))
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}
