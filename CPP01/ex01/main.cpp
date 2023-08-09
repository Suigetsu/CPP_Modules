/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:57:05 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/09 15:05:48 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *obj;
	int		i;

	i = 0;
	obj = zombieHorde(5, "peepo");
	while (i < 5)
		obj[i++].announce();
	delete[] obj;
	return (0);
}
