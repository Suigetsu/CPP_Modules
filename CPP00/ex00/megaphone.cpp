/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:02:02 by mlagrini          #+#    #+#             */
/*   Updated: 2023/07/29 11:56:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			av[i][j] = std::toupper(av[i][j]);
			std::cout << av[i][j++];
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
