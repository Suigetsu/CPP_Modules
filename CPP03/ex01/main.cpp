/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:10:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/19 11:04:34 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap		dflt;
	// ClapTrap		clap("clap");
	// ClapTrap		trap(clap);
	ScavTrap		scav;
	ScavTrap		trap("trap");
	ScavTrap		chihaja(trap);
	std::string		cmd;
	unsigned int	amount;
	
	std::cout << std::endl;
	std::cout << "Disclaimer: This is just a way to test and ensure that the implementation of the class ClapTrap is working as intended. Please do not abuse it!" << std::endl;
	while (true)
	{
		std::cout << std::endl;
		// std::cout << "---------------------" << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "  *Attack    *Repair    *Takedmg    *Exit    *Keeper" << std::endl;
		std::cout << "enter a command: ";
		std::cin >> cmd;
		if (cmd == "Attack")
		{
			std::cout << "enter the target name: ";
			std::cin >> cmd;
			std::cout << std::endl;
			scav.attack(cmd);
			dflt.attack(cmd);
			trap.attack(cmd);
			chihaja.attack(cmd);
		}
		if (cmd == "Repair")
		{
			std::cout << "enter the amount of HP you want to repair (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			scav.beRepaired(amount);
			dflt.beRepaired(amount);
			trap.beRepaired(amount);
			chihaja.beRepaired(amount);
		}
		if (cmd == "Takedmg")
		{
			std::cout << "enter the amount of AD you'll get (this takes uints only): ";
			std::cin >> amount;
			std::cout << std::endl;
			scav.takeDamage(amount);
			dflt.takeDamage(amount);
			trap.takeDamage(amount);
			chihaja.takeDamage(amount);
		}
		if (cmd == "Exit")
			return (0);
		if (cmd == "Keeper")
		{
			scav.guardGate();
			trap.guardGate();
			chihaja.guardGate();
		}
	}
	std::cout << std::endl;
	return (0);
}
