/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:29:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/10 18:36:49 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>

class Sed
{
	public:
		std::fstream	file;
		std::string		line;
		std::string		filename;
		std::string		replaced;
		size_t			pos;
		bool			flag;
		Sed();
		~Sed();
};

#endif
