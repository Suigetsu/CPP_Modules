/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:17:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/09 15:02:22 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void		announce(void);
		void		setZombie(std::string name);
		std::string	getZombie();
};
Zombie*	zombieHorde(int N, std::string name);

#endif
