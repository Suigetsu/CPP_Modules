/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:10:36 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/06 13:18:36 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to the crappy awesome PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::setContactIndex(int index)
{
	this->index = index;
}

Contact	PhoneBook::getContact(void)
{
	return (cont_arr[index]);
}
