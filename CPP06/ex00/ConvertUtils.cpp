/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:17:28 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/31 17:26:03 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	isInf(std::string literal)
{
	if (literal == "+inf" || literal == "+inff")
		return (PLUS_INF);
	else if (literal == "-inf" || literal == "-inff")
		return (MIN_INF);
	return (0);
}

void	convertToChar(std::string literal, int type)
{
	char *p_end;
	errno = 0;
	const long i = std::strtol(literal.c_str(), &p_end, 10);
	if (errno == ERANGE)
		throw (ScalarConverter::ConvertErrorException());
	if (type == CHAR_TYPE)
	{
		std::cout << "char: " << "'" << literal << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl; 
	}
	else
	{
		if (!std::isprint(i) && i <= 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (std::isprint(i))
			std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			throw (ScalarConverter::ConvertErrorException());
	}
}

void	convertToInt(std::string literal, int type)
{
	char *p_end;
	errno = 0;
	const long i = std::strtol(literal.c_str(), &p_end, 10);
	if (errno == ERANGE)
		throw (ScalarConverter::ConvertErrorException());
	if (type != CHAR_TYPE)
		std::cout << "int: " << i << std::endl;
}

void	convertToFloat(std::string literal, int type, int precision)
{
	char *p_end;
	errno = 0;
	const float i = std::strtof(literal.c_str(), &p_end);
	if (errno == ERANGE || errno == EINVAL)
		throw (ScalarConverter::ConvertErrorException());
	if (type != CHAR_TYPE)
	{
		if (i - static_cast<int>(i) == 0)
			std::cout << "float: " << i << ".0f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(precision) << i << "f" << std::endl;
	}
}

void	convertToDouble(std::string literal, int type, int precision)
{
	char *p_end;
	errno = 0;
	const double i = std::strtod(literal.c_str(), &p_end);
	if (errno == ERANGE || errno == EINVAL)
		throw (ScalarConverter::ConvertErrorException());
	if (type != CHAR_TYPE)
	{
		if (i - static_cast<int>(i) == 0)
			std::cout << "double: " << i << ".0" << std::endl;
		else
			std::cout << "double: " << std::setprecision(precision) << i << std::endl;
	}
}


int	findType(std::string literal, int &precision)
{
	int	i;

	i = 0;
	if (isInf(literal))
		return (isInf(literal));
	if (literal.length() == 1 && !std::isdigit(literal[i]))
		return (CHAR_TYPE);
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (literal[i] && std::isdigit(literal[i]))
		i++;
	if (!literal[i])
		return (INT_TYPE);
	if (literal[i] != '.')
		return (NAN_TYPE);
	else
		i++;
	while (literal[i] && std::isdigit(literal[i]))
	{
		precision++;
		i++;
	}
	if (!literal[i])
		return (DOUBLE_TYPE);
	else if (literal[i] == 'f' && !literal[i + 1])
		return (FLOAT_TYPE);
	return (NAN_TYPE);	
}
