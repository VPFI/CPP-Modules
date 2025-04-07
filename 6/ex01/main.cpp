/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:45:31 by vpf               #+#    #+#             */
/*   Updated: 2025/04/07 19:14:48 by vperez-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		Data1(30);
	Data *		deserializedData;
	uintptr_t	serializedData;

	std::cout << "Data: " << Data1.getData() << std::endl;
	std::cout << "Address: " << &Data1 << std::endl << std::endl;

	serializedData = Serializer::serialize(&Data1);
	std::cout << "Serialized data: " << serializedData << std::endl << std::endl;

	deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Data: " << Data1.getData() << std::endl;
	std::cout << "Deserialized address: " << deserializedData << std::endl;
	std::cout << "Data: " << deserializedData->getData() << std::endl << std::endl;

	serializedData = Serializer::serialize(deserializedData);
	std::cout << "New serialized data: " << serializedData << std::endl;
	return (0);
}
