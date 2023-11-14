/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:14:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/14 10:23:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int	arr[] = {2, -1, 4, 15, 0};
	int len = sizeof(arr) / sizeof(arr[0]);
	std::string strArr[] = {"hello", "world", "1337", "most generic string"};
	::iter(arr, len, printElement<int>);
	::iter(strArr, sizeof(strArr)/sizeof(strArr[0]), printElement<std::string>);
}
