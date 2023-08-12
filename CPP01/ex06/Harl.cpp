/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:41:17 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/11 12:15:57 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	
}

Harl::~Harl()
{

}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger! If you did,";
	std::cout << " I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started working";
	std::cout << " here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int	assignInt(std::string level)
{
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4)
	{
		if (level == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	int			i;
	void	(Harl::*MemFn[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = assignInt(level);
	switch (i)
	{
		case 0:
			(this->*MemFn[0])();
			return ;
		case 1:
			(this->*MemFn[1])();
			return ;
		case 2:
			(this->*MemFn[2])();
			return ;
		case 3:
			(this->*MemFn[3])();
			return ;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

