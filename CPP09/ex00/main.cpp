/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/21 09:52:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	openInputFile(std::string filename, BitcoinExchange &obj)
{
	std::fstream	file;
	std::string		line;
	struct tm		tm;
	double			price;
	char			*pEnd;
	
	(void)obj;
	errno = 0;
	file.open(filename);
	if (!file.is_open())
		throw (cannotOpenFileException());
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string token = line.substr(0, line.find(" | "));
		if (!strptime(token.c_str(), "%Y-%m-%d", &tm))
		{
			std::cout << "Error: bad input => " << token << std::endl;
			continue ;
		}
		if (line.find(" | ") != 10)
		{
			std::cout << "Error: bad input => no value." << std::endl;
			continue ;
		}
		line.erase(0, line.find(" | ") + 3);
		price = std::strtod(line.c_str(), &pEnd);
		if (errno == EINVAL)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			errno = 0;
			continue ;
		}
		else if (price < 0 || price > 1000)
		{
			if (price < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue ;
			}
			std::cout << "Error: very large number." << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator it = obj.getMap().lower_bound(token);
		if (it != obj.getBeginIterator())
		{
			if (it->first != token)
				it--;
		}
		else
		{
			if (it->first != token)
			{
				std::cout << "Error: no exchange rate is found." << std::endl;
				continue ;
			}
		}
		double value = price * it->second;
		std::cout << token << " => " << price << " = " << value << std::endl;
	}
}

int	main(int ac, char **av)
{
	
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	obj;
		openInputFile(av[1], obj);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
