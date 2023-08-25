/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:28:35 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/24 12:36:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*dogIdeas;
	public:
		Dog();
		Dog(const Dog &obj);
		~Dog();
		Dog			&operator=(const Dog &obj);
		void		makeSound() const;
		std::string	getType() const;
};

#endif
