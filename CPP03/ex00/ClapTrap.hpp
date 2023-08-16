/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:51:48 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/16 18:47:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		std::string		name;
		unsigned int	HitPts;
		unsigned int	NrgPts;
		unsigned int	Ad;
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &obj );
		~ClapTrap();
		ClapTrap	&operator=( const ClapTrap &obj );
		void		attack( const std::string &target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

#endif