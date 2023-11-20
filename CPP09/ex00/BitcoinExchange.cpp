/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/20 15:16:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *cannotOpenFileException::what() const throw ()
{
	return ("Error: could not open file.");
}

BitcoinExchange::BitcoinExchange()
{
	
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		return (*this);
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	
}

std::map<std::string, double>	&BitcoinExchange::getMap()
{
	return (this->dataMap);
}

std::map<std::string, double>::iterator	BitcoinExchange::getBeginIterator()
{
	return (this->dataMap.begin());
}

std::map<std::string, double>::iterator	BitcoinExchange::getEndIterator()
{
	return (this->dataMap.end());
}
