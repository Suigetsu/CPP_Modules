/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/30 11:35:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define NAN_TYPE 0
# define CHAR_TYPE 1
# define INT_TYPE 2
# define FLOAT_TYPE 3
# define DOUBLE_TYPE 4
# define PLUS_INF 5
# define MIN_INF 6

# include <iostream>
# include <limits>
# include <iomanip>

class	ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);		
	public:
		static void	convert(std::string literal);
		class	ConvertErrorException : public std::exception
		{
			public:
				const char *what() const throw();	
		};
		~ScalarConverter();
};

int		findType(std::string literal, int &precision);
void	convertToChar(std::string literal, int type);
void	convertToInt(std::string literal, int type);
void	convertToFloat(std::string literal, int type, int precision);
void	convertToDouble(std::string literal, int type, int precision);

#endif
