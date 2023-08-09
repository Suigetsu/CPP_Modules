/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:30:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/09 15:08:48 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *obj_arr;
	int		i;

	i = 0;
	obj_arr = new Zombie[N];
	while (i < N)
		obj_arr[i++].setZombie(name);
	return (obj_arr);
}
