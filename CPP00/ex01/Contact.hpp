/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:38:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/05 22:44:35 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	phonenbr;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	darkscrt;
	public:
		Contact();
		~Contact();
		void	setContactNbr(std::string nbr);
		void	setContactFn(std::string firstname);
		void	setContactLn(std::string lastname);
		void	setContactNn(std::string nickname);
		void	setContactDs(std::string darkscrt);
};


#endif
