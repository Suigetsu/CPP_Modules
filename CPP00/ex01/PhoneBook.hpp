/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:39 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/06 21:28:57 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	cont_arr[8];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		void	setContactIndex(int index);
		Contact	*getContact(void);
};

#endif
