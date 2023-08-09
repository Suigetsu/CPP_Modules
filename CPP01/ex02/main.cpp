/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:00:27 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/09 17:54:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str;
	std::string	*stringPTR;
	std::string	&stringREF = str;
	
	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	std::cout << "THIS IS THE ADDRESS OF str: " << &str << std::endl;
	std::cout << "THIS IS THE ADDRESS HELD BY stringPTR: " << stringPTR << std::endl;
	std::cout << "THIS IS THE ADDRESS HELD BY stringREF: " << &stringREF << std::endl;
	std::cout << "The value of str: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}
