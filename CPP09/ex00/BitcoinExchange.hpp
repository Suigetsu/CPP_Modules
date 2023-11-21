/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/21 10:44:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <algorithm>
# include <map>
# include <iterator>
# include <iostream>
# include <sstream>
# include <fstream>
# include <ctime>
# include <string>
# include <exception>

class	cannotOpenFileException : public std::exception
{
	public:
		const char * what() const throw ();
};

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	dataMap;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
		std::map<std::string, double>			&getMap();
		std::map<std::string, double>::iterator	getBeginIterator();
		std::map<std::string, double>::iterator	getEndIterator();
		void	convertBTC(std::string filename);
};

#endif
