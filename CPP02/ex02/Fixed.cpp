/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:18:22 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/15 18:34:17 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractValue = 8;

Fixed::Fixed( void )
{
	this->intValue = 0;
}

Fixed::Fixed( const int n )
{
	this->intValue = n << fractValue;
}

Fixed::Fixed( const float n )
{
	this->intValue = roundf(n * (1 << fractValue));
}

Fixed::Fixed( const Fixed &f )
{
	this->operator=(f);
}

Fixed::~Fixed( void )
{
}

Fixed	&Fixed::operator=( const Fixed &f )
{
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

bool	Fixed::operator>( const Fixed &f ) const
{
	if (this->getRawBits() > f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<( const Fixed &f ) const
{
	if (this->getRawBits() < f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=( const Fixed &f ) const
{
	if (this->getRawBits() >= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=( const Fixed &f ) const
{
	if (this->getRawBits() <= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==( const Fixed &f ) const
{
	if (this->getRawBits() != f.getRawBits())
		return (false);
	return (true);
}

bool	Fixed::operator!=( const Fixed &f ) const
{
	if (this->getRawBits() == f.getRawBits())
		return (false);
	return (true);
}

Fixed	Fixed::operator+( const Fixed &f ) const
{
	float	sum = this->toFloat() + f.toFloat();
	return (Fixed(sum));
}

Fixed	Fixed::operator-( const Fixed &f ) const
{
	float	sub = this->toFloat() - f.toFloat();
	return (Fixed(sub));
}

Fixed	Fixed::operator*( const Fixed &f ) const
{
	float	mult = this->toFloat() * f.toFloat();
	return (Fixed(mult));
}

Fixed	Fixed::operator/( const Fixed &f ) const
{
	float	div = this->toFloat() / f.toFloat();
	return (Fixed(div));
}

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return (b);
	return (a);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	&Fixed::operator++()
{
	++this->intValue;
	return (*this);
}
Fixed	Fixed::operator++( int )
{
	Fixed	temp(*this);
	operator++();
	return (temp);
}

Fixed	&Fixed::operator--()
{
	--this->intValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	operator--();
	return (temp);
}
