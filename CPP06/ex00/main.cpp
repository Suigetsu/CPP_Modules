/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:29 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/29 10:48:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: the program takes only one argument." << std::endl;
		exit (EXIT_FAILURE);
	}
	ScalarConverter::convert(static_cast<std::string>(av[1]));
	return (EXIT_SUCCESS);
}
