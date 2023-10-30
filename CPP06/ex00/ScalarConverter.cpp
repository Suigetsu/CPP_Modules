/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:40 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/30 11:50:23 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{

}

const char *ScalarConverter::ConvertErrorException::what() const throw ()
{
	return ("impossible");
}

void	ScalarConverter::convert(std::string literal)
{
	int		type;
	int		precision;
	char	sign;

	precision = 2;
	type = findType(literal, precision);
	if (type == PLUS_INF || type == MIN_INF)
	{
		if (type == PLUS_INF)
			sign = '+';
		else
			sign = '-';
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Decimal: impossible" << std::endl;
		std::cout << "Float: "  << sign << "inff" << std::endl;
		std::cout << "Double: " << sign << "inf" << std::endl;		  
	}
	else if (type == NAN_TYPE)
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Decimal: impossible" << std::endl;
		std::cout << "Float: nanf" << std::endl;
		std::cout << "Double: nan" << std::endl;
	}
	else
	{
		try
		{
			convertToChar(literal, type);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Char: ";
			std::cerr << e.what() << std::endl;
		}
		try
		{
			convertToInt(literal, type);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Decimal: ";
			std::cerr << e.what() << std::endl;
		}
		try
		{
			convertToFloat(literal, type, precision);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Float: ";
			std::cerr << e.what() << std::endl;
		}
		try
		{
			convertToDouble(literal, type, precision);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Double: ";
			std::cerr << e.what() << std::endl;
		}
	}
}
