/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:38:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/05 21:44:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		unsigned int	phonenbr;
		std::string		firstname;
		std::string		lastname;
		std::string		nickname;
		std::string		darkscrt;
	public:
		Contact();
		~Contact();
		void	setContactNbr(unsigned int nbr);
		void	setContactFn(std::string firstname);
		void	setContactLn(std::string lastname);
		void	setContactNn(std::string nickname);
		void	setContactDs(std::string darkscrt);
};


#endif
