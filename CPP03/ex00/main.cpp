/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:10:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/17 10:41:43 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap		dflt;
	ClapTrap		clap("clap");
	ClapTrap		trap(clap);
	std::string		cmd;
	unsigned int	amount;
	
	std::cout << std::endl;
	std::cout << "Disclaimer: This is just a way to test and ensure that the implementation of the class ClapTrap is working as intended!" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		// std::cout << "---------------------" << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "  *Attack    *Repair    *Takedmg" << std::endl;
		std::cout << "enter a command: ";
		std::cin >> cmd;
		if (cmd == "Attack")
		{
			std::cout << "enter the target name: ";
			std::cin >> cmd;
			std::cout << std::endl;
			dflt.attack(cmd);
			clap.attack(cmd);
			trap.attack(cmd);
		}
		if (cmd == "Repair")
		{
			std::cout << "enter the amount of HP you want to repair (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			dflt.beRepaired(amount);
			clap.beRepaired(amount);
			trap.beRepaired(amount);
		}
		if (cmd == "Takedmg")
		{
			std::cout << "enter the amount of AD you'll get (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			dflt.takeDamage(amount);
			clap.takeDamage(amount);
			trap.takeDamage(amount);
		}
	}
	std::cout << std::endl;
	return (0);
}
