/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:22:13 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/25 13:24:59 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &obj);
		~Brain();
		Brain	&operator=(const Brain &obj);
};

#endif
