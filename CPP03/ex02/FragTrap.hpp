/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:18:29 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 11:52:59 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &obj );
		~FragTrap();
		FragTrap	&operator=( const FragTrap &obj );
		void	highFivesGuys( void );
};

#endif
