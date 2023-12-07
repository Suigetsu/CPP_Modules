/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/12/07 12:09:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char *cannotOpenFileException::what() const throw ()
{
	return ("Error: could not open file.");
}

const char *badHeaderException::what() const throw ()
{
	return ("Error: Bad header");
}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	std::fstream	dataFile;
	
	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw (cannotOpenFileException());
	std::getline(dataFile, line);
	if (line != "date,exchange_rate")
		throw(cannotOpenFileException());
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

void	BitcoinExchange::convertBTC(std::string filename)
{
	std::fstream	file;
	std::string		line;
	struct tm		tm;
	double			price;
	char			*pEnd;
	
	errno = 0;
	file.open(filename);
	if (!file.is_open())
		throw (cannotOpenFileException());
	std::getline(file, line);
	if (line != "date | value")
		throw(badHeaderException());
	while (std::getline(file, line))
	{
		if (line == "")
			continue ;
		std::string token = line.substr(0, line.find(" | "));
		if (!strptime(token.c_str(), "%Y-%m-%d", &tm))
		{
			std::cout << "Error: bad input => " << token << std::endl;
			continue ;
		}
		else if (std::strncmp(&token.c_str()[token.length() - 2], "00", token.length() - 2) == 0)
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
		if (errno == EINVAL || *pEnd != '\0')
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
		std::map<std::string, double>::iterator it = this->dataMap.lower_bound(token);
		if (it != this->dataMap.begin())
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
