/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:29:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/14 17:25:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					intValue;
		static const int	fractValue;
	public:
		Fixed( void );
		Fixed( const Fixed &f );
		~Fixed( void );
		Fixed	&operator=( const Fixed &f );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
