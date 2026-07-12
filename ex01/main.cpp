/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:59:38 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 18:29:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data data;

	data.value = 42;

	uintptr_t 	raw 		= Serializer::serialize(&data);
	Data* 		restored 	= Serializer::deserialize(raw);

	std::cout << "Original pointer : " << &data 			<< std::endl;
	std::cout << "Serialized value : " << raw 				<< std::endl;
	std::cout << "Restored pointer : " << restored 		  	<< std::endl;
	std::cout << "Value            : " << restored->value 	<< std::endl;

	return (0);
}

// int main(void)
// {
// 	std::cout << "======================================" << std::endl;
// 	std::cout << "        Step 1 - Data Object" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	Data data;
// 	data.value = 42;

// 	std::cout << "Type  : Data" << std::endl;
// 	std::cout << "Value : Address = " << &data
// 			  << ", value = " << data.value << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "======================================" << std::endl;
// 	std::cout << "       Step 2 - Data Pointer" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	Data* ptr = &data;

// 	std::cout << "Type  : Data*" << std::endl;
// 	std::cout << "Value : " << ptr << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "======================================" << std::endl;
// 	std::cout << "    Step 3 - Serialize Pointer" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	uintptr_t raw = Serializer::serialize(ptr);

// 	std::cout << "Type  : uintptr_t" << std::endl;
// 	std::cout << "Value : " << raw << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "======================================" << std::endl;
// 	std::cout << "   Step 4 - Deserialize Pointer" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	Data* restored = Serializer::deserialize(raw);

// 	std::cout << "Type  : Data*" << std::endl;
// 	std::cout << "Value : " << restored << std::endl;

// 	std::cout << std::endl;

// 	std::cout << "======================================" << std::endl;
// 	std::cout << "           Verification" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	if (ptr == restored)
// 		std::cout << "SUCCESS : Original and restored pointers are identical." << std::endl;
// 	else
// 		std::cout << "ERROR   : Pointers are different." << std::endl;


// 	return (0);
// }
