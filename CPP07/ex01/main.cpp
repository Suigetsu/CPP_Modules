/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:14:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/05 11:19:40 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int	arr[] = {2, -1, 4, 15, 0};
	int len = sizeof(arr) / sizeof(arr[0]);
	std::string strArr[] = {"hello", "world", "1337", "most generic string"};
	::iterate(arr, len, printElement<int>);
	::iterate(strArr, sizeof(strArr)/sizeof(strArr[0]), printElement<std::string>);
}
