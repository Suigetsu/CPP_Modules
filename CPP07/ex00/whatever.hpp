/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:40:03 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/04 18:12:09 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>

template <class T>
void    swap (T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <class T>
T   min (T a, T b)
{
	if (a > b)
		return (b);
	return (a);
}

template <class T>
T   max (T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif
