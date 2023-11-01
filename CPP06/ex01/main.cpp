/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:59 by mlagrini          #+#    #+#             */
/*   Updated: 2023/10/31 16:49:18 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		*data = NULL;
	Data		*deserializedData;
	uintptr_t	serializedData;
	
	data = new Data;
	data->i = 10;
	data->str = "hello";
	// serializedData = Serializer::serialize(data);
	std::cout << serializedData << std::endl;
	deserializedData = Serializer::deserialize(serializedData);
	if (deserializedData == data)
		std::cout << "Cast is working!" << std::endl;
	else
		std::cout << "Cast failed!" << std::endl;
	delete data;
	return (EXIT_SUCCESS);
}
