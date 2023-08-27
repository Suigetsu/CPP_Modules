/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:58:25 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/26 19:34:57 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class	Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const & type);
		Ice(const Ice &obj);
		~Ice();
		Ice		&operator=(const Ice &obj);
		AMateria	*clone() const;
        void         use(ICharacter& target);
};

#endif
