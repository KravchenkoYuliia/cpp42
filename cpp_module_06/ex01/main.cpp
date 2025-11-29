/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:44:22 by yukravch          #+#    #+#             */
/*   Updated: 2025/11/21 14:44:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main() {
	
	Data*		someData = new Data;
	uintptr_t	resultOfSerialization = Serializer::serialize(someData);
	Data*		resultofDeserialization = Serializer::deserialize(resultOfSerialization);
	
	std::cout << "the address of Data strucuture in hexa [" << someData << "]" << std::endl
		  << "resultat of serialization: [" << resultOfSerialization << "]" << std::endl
		  << "result of deserialization: [" << resultofDeserialization << "]" << std::endl;
	
	delete someData;
	return 0;
}
