/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:45:31 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/14 18:48:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractValue = 8;

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->intValue = 0;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	this->intValue = n << fractValue;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	this->intValue = roundf(n * (1 << fractValue));
}

Fixed::Fixed( const Fixed &f )
{
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(f);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed &f )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this->intValue != f.getRawBits())
		this->intValue = f.intValue;
	return *this;
}

void	Fixed::setRawBits( int const raw )
{
	this->intValue = raw;
}

int	Fixed::getRawBits( void ) const
{
	return (this->intValue);
}

int	Fixed::toInt( void ) const
{
	int	i;
	
	i = (this->intValue >> fractValue);
	return (i);
}

float	Fixed::toFloat( void ) const
{
	float	f;
	
	f = (static_cast<float>(this->intValue) / (1 << fractValue));
	return (f);
}

std::ostream	&operator<<( std::ostream &out, const Fixed &f )
{
	out << f.toFloat();
	return (out);
}
