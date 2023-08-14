/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:05:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/14 18:26:07 by mlagrini         ###   ########.fr       */
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
		Fixed	&operator=( const Fixed &f );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};
std::ostream	&operator<<( std::ostream &out, const Fixed &f );

#endif
