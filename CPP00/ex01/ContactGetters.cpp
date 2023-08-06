/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactGetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:26:22 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/06 17:19:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getContactNbr(void)
{
	return (this->phonenbr);
}

std::string	Contact::getContactFn(void)
{
	return (this->firstname);
}

std::string	Contact::getContactLn(void)
{
	return (this->lastname);
}

std::string	Contact::getContactNn(void)
{
	return (this->nickname);
}

std::string	Contact::getContactDs(void)
{
	return (this->darkscrt);
}
