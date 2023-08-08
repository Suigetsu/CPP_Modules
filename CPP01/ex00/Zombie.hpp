/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:17:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/08 20:19:59 by mlagrini         ###   ########.fr       */
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
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
