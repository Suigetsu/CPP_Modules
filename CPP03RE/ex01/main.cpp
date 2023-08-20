/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:46:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/20 16:33:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap		noname;
	ScavTrap		named("bot");
	ScavTrap		copied(named);
	std::string		cmd;
	unsigned int	amount;

	std::cout << std::endl << "**************************" << std::endl << std::endl;
	std::cout << "Disclaimer: This program's purpose it to test whether this working or not. Do not abuse it!" << std::endl;
	std::cout << std::endl << "**************************" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "  *Attack    *Repair    *Takedmg    *Stats    *Keeper    *Exit" << std::endl;
		std::cout << "enter a command: ";
		std::cin >> cmd;
		if (cmd == "Attack")
		{
			std::cout << "enter the target's name: ";
			std::cin >> cmd;
			std::cout << std::endl;
			noname.attack(cmd);
			named.attack(cmd);
			copied.attack(cmd);
		}
		else if (cmd == "Repair")
		{
			std::cout << "enter the amount of HP you want to repair (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			noname.beRepaired(amount);
			named.beRepaired(amount);
			copied.beRepaired(amount);
		}
		else if (cmd == "Takedmg")
		{
			std::cout << "enter the amount of AD you'll get (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			noname.takeDamage(amount);
			named.takeDamage(amount);
			copied.takeDamage(amount);
		}
		else if (cmd == "Stats")
		{
			noname.showStats();
			named.showStats();
			copied.showStats();
		}
		else if (cmd == "Keeper")
		{
			noname.guardGate();
			named.guardGate();
			copied.guardGate();
		}
		else if (cmd == "Exit")
			return (0);
		else
			std::cout << std::endl << "this option is not available. try again!" << std::endl;
	}
	return (0);
}
