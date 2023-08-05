/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactSetters.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:47:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/05 21:49:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void    Contact::setContactNbr(unsigned int nbr)
{
    this->phonenbr = nbr;
}

void	Contact::setContactFn(std::string firstname)
{
    this->firstname = firstname;
}

void	Contact::setContactLn(std::string lastname)
{
    this->lastname = lastname;
}

void	Contact::setContactNn(std::string nickname)
{
    this->nickname = nickname;
}

void	Contact::setContactDs(std::string darkscrt)
{
    this->darkscrt = darkscrt;
}