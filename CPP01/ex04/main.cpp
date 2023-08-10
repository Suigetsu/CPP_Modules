/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:58:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/10 18:44:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int ac, char **av)
{
	Sed	obj;

	obj.pos = 0;
	obj.flag = false;
	if (ac != 4)
	{
		std::cout << "Wrong args number!" << std::endl;
		return (1);
	}
	obj.file.open(av[1], std::ios::in);
	if (!obj.file.is_open())
	{
		std::cout << "File doesn't exist." << std::endl;
		return (1);
	}
	obj.filename = av[1] + static_cast<std::string>(".replace");
	while(getline(obj.file, obj.line))
	{
		obj.pos = 0;
		while (obj.pos != std::string::npos && av[2][obj.pos] != '\0')
		{
			obj.pos = obj.line.find(av[2], obj.pos);
			if (obj.pos == std::string::npos)
				break ;
			obj.line.erase(obj.pos, strlen(av[2]));
			obj.line.insert(obj.pos, av[3]);
			obj.flag = true;
		}
		obj.replaced += obj.line;
		obj.replaced += '\n';
	}
	obj.file.close();
	if (obj.flag == true)
	{
		obj.file.open(obj.filename, std::ios::out);
		if (!obj.file.is_open())
		{
			std::cout << "A problem has occured." << std::endl;
			return (1);
		}
		obj.file << obj.replaced;
	}
	obj.file.close();
}
