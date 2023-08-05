/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/05 22:28:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	AssignInfo(PhoneBook pb, std::string cmd, int index)
{
	std::string		str;
	
	while (1)
	{
		pb.setContactIndex(index);
		while (1)
		{
			std::cout << "Enter the first name: ";
			if (!std::getline(std::cin, str))
				exit (0);
			if (str.empty())
				continue ;
			pb.getContact().setContactFn(str);
			break ;	
		}
		while (1)
		{
			std::cout << "Enter the last name: ";
			if (!std::getline(std::cin, str))
				exit (0);
			if (str.empty())
				continue ;
			pb.getContact().setContactLn(str);
			break ;
		}
		while (1)
		{
			std::cout << "Enter the nickname: ";
			if (!std::getline(std::cin, str))
				exit (0);
			if (str.empty())
				continue ;
			pb.getContact().setContactNn(str);
			break ;
		}
		std::cout << "Enter the phone number: ";
		if (!std::getline(std::cin, str))
			exit (0);
		if (str.empty())
			continue ;
		if (CheckValidNbr(str))
		{
			std::cout << "The number is not valid" << std::endl;
			continue ;
		}
		break ;
		}
}

void	Commands(PhoneBook pb, std::string cmd, int index)
{
	if (cmd == "ADD")
		AssignInfo(pb, cmd, index);
}

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;
	int			counter;
	
	counter = 0;
	while (1)
	{
		std::cout << "Enter a command: ";
		if(!std::getline(std::cin, cmd))
			return (0);
		if (cmd.empty())
			continue ;
		if (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT")
		{
			std::cout << "This command doesn't exist" << std::endl;
			continue ;
		}
		Commands(pb, cmd, counter);
	}
	return (0);
}
