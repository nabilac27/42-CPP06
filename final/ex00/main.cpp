/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:10:21 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/16 15:26:08 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./converter <literal>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}


/* **************************** */

// int main(void)
// {
// 	double value = 65;

// 	// Implicit conversion
// 	int implicit = value;
	
// 	std::cout << "Implicit        : " << implicit << std::endl;                    	

// 	// Explicit conversion
// 	// int explicitCast = static_cast<int>(value); 	

// 	// std::cout << "static_cast<int>: " << explicitCast << std::endl;

// 	return (0);
// }