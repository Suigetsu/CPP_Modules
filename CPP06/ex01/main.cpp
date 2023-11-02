/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/11/02 10:06:43 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		*data = NULL;
	Data		*deserializedData;
	uintptr_t	serializedData;
	
	data = new Data;
	data->i1 = 10;
	data->i2 = 20;
	data->c = 'C';
	data->b = true;
	serializedData = Serializer::serialize(data);
	// std::cout << serializedData << std::endl;
	deserializedData = Serializer::deserialize(serializedData);
	if (deserializedData == data)
		std::cout << "Cast is working!" << std::endl;
	else
		std::cout << "Cast failed!" << std::endl;
	std::cout << *reinterpret_cast<int *>(deserializedData) << std::endl;
	int *ptr = reinterpret_cast<int *>(deserializedData);
	ptr++;
	std::cout << *ptr << std::endl;
	ptr++;
	char *ptr2 = reinterpret_cast<char *>(ptr);
	std::cout << *ptr2 << std::endl;
	ptr2++;
	std::cout << *reinterpret_cast<bool *>(ptr2) << std::endl;
	delete data;
	return (EXIT_SUCCESS);
}
