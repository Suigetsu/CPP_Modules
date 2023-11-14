/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:14:04 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/14 10:25:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T *arr, int len, F func)
{
	int i = 0;
    while (i < len)
        func(arr[i++]);
}
template <typename T>
void    printElement(T &element)
{
    std::cout << element << std::endl;
}

#endif

