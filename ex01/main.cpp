/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:59:38 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 02:18:18 by nchairun         ###   ########.fr       */
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

	// -------------------
	
	// Data data;
	// Data* original = &data;

	// original->value = 42;

	// uintptr_t raw = Serializer::serialize(original);
	// Data* restored = Serializer::deserialize(raw);

	// std::cout << "Original pointer : " << original << std::endl;
	// std::cout << "Serialized value : " << raw << std::endl;
	// std::cout << "Restored pointer : " << restored << std::endl;
	// std::cout << "Value            : " << restored->value << std::endl;

	// if (original == restored)
    // std::cout << "Pointers are equal ✔" << std::endl;
	
	return (0);
}

/*
	uintptr_t 		= an unsigned integer type that is guaranteed to be large enough to store a pointer.
	
	reinterpret_cast 
	This tells C++:
		Treat these bits as another type.

	It does not change the value.

	It only changes how the compiler interprets it.

	Imagine this:
		Before
			ptr
			↓
			0x7ffee4b0

		After
			reinterpret_cast<uintptr_t>(ptr)
			140732734861488

	Same address.

	Different type.
*/