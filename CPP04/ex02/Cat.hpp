/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:37:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/24 12:36:02 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain	*catIdeas;
	public:
		Cat();
		Cat(const Cat &obj);
		~Cat();
		Cat			&operator=(const Cat &obj);
		void		makeSound() const;
		std::string	getType() const;
};

#endif
