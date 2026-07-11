/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:10:21 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/11 23:28:57 by nchairun         ###   ########.fr       */
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
