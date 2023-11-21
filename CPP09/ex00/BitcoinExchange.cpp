/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/21 09:50:24 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *cannotOpenFileException::what() const throw ()
{
	return ("Error: could not open file.");
}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	std::fstream	dataFile;
	
	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw (cannotOpenFileException());
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		std::string token = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);
		this->dataMap[token] = std::strtod(line.c_str(), NULL);
	}
	dataFile.close();
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	this->dataMap = obj.dataMap;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->dataMap = obj.dataMap;
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
