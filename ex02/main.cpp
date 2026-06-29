/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:26:56 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/29 13:22:47 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"

int main ()
{
	Base* obj = generate(); // generate random class between A, B, C

	std::cout << "Identifying using pointer: ";
	identify(obj); // identify using pointer

	std::cout << "Identifying using reference: ";
	identify(*obj); // identify using reference

	// std::cout << "Testing nullptr:" << std::endl;
    // identify(nullptr); // check nullptr

	delete obj; // delete dynamically allocated object
	return 0;
}