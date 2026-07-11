/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:10:21 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/11 23:08:11 by nchairun         ###   ########.fr       */
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


// int main(void)
// {

//     // double -> int
// 		double 	d 	=	 42.8;
// 		int		num = static_cast<int>(d);

// 		std::cout << "double -> int     : " << num << std::endl;

//     // Invalid conversion
// 		// std::string text 	= "42";
// 		// int 		number 	= static_cast<int>(text);

// 		// std::cout << "string -> int     : impossible using static_cast" << std::endl; // ❌ This does NOT compile.

//     return (0);
// }
