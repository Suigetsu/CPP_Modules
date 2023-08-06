/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:01 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/06 22:52:20 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

bool	CheckValidNbr(std::string str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (true);
		i++;
	}
	return (false);
}

Contact	AssignInfo(void)
{
	std::string		str;
	Contact			obj;
	
	while (1)
	{
		while (1)
		{
			std::cout << "Enter the first name: ";
			if (!std::getline(std::cin, str))
				exit (1);
			if (str.empty())
				continue ;
			obj.setContactFn(str);
			break ;	
		}
		while (1)
		{
			std::cout << "Enter the last name: ";
			if (!std::getline(std::cin, str))
				exit (1);
			if (str.empty())
				continue ;
			obj.setContactLn(str);
			break ;
		}
		while (1)
		{
			std::cout << "Enter the nickname: ";
			if (!std::getline(std::cin, str))
				exit (1);
			if (str.empty())
				continue ;
			obj.setContactNn(str);
			break ;
		}
		while (1)
		{
			std::cout << "Enter the phone number: ";
			if (!std::getline(std::cin, str))
				exit (1);
			if (str.empty())
				continue ;
			if (CheckValidNbr(str))
			{
				std::cout << "Invalid input" << std::endl;
				continue ;
			}
			obj.setContactNbr(str);
			break ;
		}
		while (1)
		{
			std::cout << "Enter your darkest secret: ";
			if (!std::getline(std::cin, str))
				exit (1);
			if (str.empty())
				continue ;
			obj.setContactDs(str);
			break ;
		}
		std::cout << "Your contact has been added!!" << std::endl;
		break ;
	}
	return (obj);
}

void	printCharacters(std::string str)
{
	int		i;
	size_t	len;

	i = 0;
	len = str.length();
	if (len > 10)
	{
		while (i < 9)
			std::cout << str[i++];
		std::cout << ".";
		return ;
	}
	std::cout << str;
	while (len < 10)
	{
		std::cout << " ";
		len++;
	}
}

void	SearchCommand(PhoneBook *pb)
{
	std::string	index;
	int			i;
	
	i = 0;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "|INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	while (i < 8)
	{
		if (!pb->getContact()[i].getContactFn().empty())
		{
			std::cout << "|" << i << "         |";
			printCharacters(pb->getContact()[i].getContactFn());
			std::cout << "|";
			printCharacters(pb->getContact()[i].getContactLn());
			std::cout << "|";
			printCharacters(pb->getContact()[i].getContactNn());
			std::cout << "|" << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
		}
		else
			break ;
		i++;
	}
	while (1)
	{
		std::cout << "Enter an index: ";
		std::cin >> index;
		if (CheckValidNbr(index))
		{
			std::cout << "Invalid input, try again." << std::endl;
			continue ;
		}
		i = std::stoi(index);
		if (!(i >= 0 && i <= 7) || pb->getContact()[i].getContactFn().empty())
		{
			std::cout << "Index doesn't exist, try again." << std::endl;
			continue ;
		}
		std::cout << "First Name: " << pb->getContact()[i].getContactFn() << std::endl;
		std::cout << "Last Name: " << pb->getContact()[i].getContactLn() << std::endl;
		std::cout << "Nickname: " << pb->getContact()[i].getContactNn() << std::endl;
		std::cout << "Phone number: " << pb->getContact()[i].getContactNbr() << std::endl;
		std::cout << "Darkest secret: " << pb->getContact()[i].getContactDs() << std::endl;
		break ;
	}
}

void	Commands(PhoneBook *pb, std::string cmd, int index)
{
	int	i;

	i = 0;
	pb->setContactIndex(index);
	if (cmd == "ADD")
		pb->getContact()[index] = AssignInfo();
	if (cmd == "EXIT")
	{
		std::cout << "Thank you for using this crappy awesome PhoneBook!" << std::endl;
		exit (0);
	}
	if (cmd == "SEARCH")
		SearchCommand(pb);
}

int	main(void)
{
	PhoneBook	pb;
	std::string	cmd;
	int			counter;
	
	counter = -1;
	while (counter < 8)
	{
		std::cout << "Enter a command: ";
		if(!std::getline(std::cin, cmd))
			return (1);
		if (cmd.empty())
			continue ;
		if (cmd != "ADD" && cmd != "SEARCH" && cmd != "EXIT")
		{
			std::cout << "This command doesn't exist" << std::endl;
			continue ;
		}
		if (cmd == "ADD")
			counter++;
		if (counter == 8)
			counter = 0;
		Commands(&pb, cmd, counter);
	}
	return (0);
}
