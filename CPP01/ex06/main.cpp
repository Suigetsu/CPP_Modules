/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:40:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/10 19:40:52 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	obj;

	if (ac != 2)
	{
		std::cout << "[ Wrong number of arguments! ]" << std::endl;
		return (1);
	}
	obj.complain(av[1]);
	return (0);
}
