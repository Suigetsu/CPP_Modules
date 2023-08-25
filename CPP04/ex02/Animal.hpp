/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:25:19 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/25 17:51:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &obj);
		virtual ~Animal();
		Animal			&operator=(const Animal &obj);
		virtual std::string		getType() const = 0;
		virtual void	makeSound() const = 0;
};

#endif
