/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:04:32 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/15 18:18:41 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					intValue;
		static const int	fractValue;
	public:
		Fixed( void );
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed &f );
		~Fixed( void );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		Fixed				&operator=( const Fixed &f );
		bool				operator>( const Fixed &f ) const;
		bool				operator<( const Fixed &f) const;
		bool				operator>=( const Fixed &f ) const;
		bool				operator<=( const Fixed &f ) const;
		bool				operator==( const Fixed &f ) const;
		bool				operator!=( const Fixed &f ) const;
		Fixed				operator+( const Fixed &f ) const;
		Fixed				operator-( const Fixed &f ) const;
		Fixed				operator*( const Fixed &f ) const;
		Fixed				operator/( const Fixed &f ) const;
		Fixed				&operator++();
		Fixed				operator++( int );
		Fixed				&operator--();
		Fixed				operator--(int);
		static Fixed		&min( Fixed &a, Fixed &b );
		static const Fixed	&min( const Fixed &a, const Fixed &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static const Fixed	&max( const Fixed &a, const Fixed &b );
};
std::ostream	&operator<<( std::ostream &out, const Fixed &f );

#endif
