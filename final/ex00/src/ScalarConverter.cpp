/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:09:27 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 15:24:56 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* ************************************************************************** */
/*  ORTHODOX CANONICAL FORM                                                   */
/* ************************************************************************** */
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}


/* ************************************************************************** */
/*  CONVERT							                                          */
/* ************************************************************************** */
void ScalarConverter::convert(const std::string& input)
{
	e_type	type;
	double	value;

	type = checkType(input);

	switch (type)
	{
		case (PSEUDO):
			printPseudoLiteral(input);
			break ;

		case (CHAR):
			printChar(input[0]);
			break ;

		case (INT):
		case (FLOAT):
		case (DOUBLE):
			errno = 0;
			value = std::strtod(input.c_str(), NULL);
			
			if (errno == ERANGE)
			{
				std::cout << "char	: impossible" 	<< std::endl;
				std::cout << "int	: impossible" 	<< std::endl;
				std::cout << "float	: impossible" 	<< std::endl;
				std::cout << "double	: impossible" << std::endl;
				return ;
			}
			
			printNumber(value);
			break ;

	default:
		std::cout << "char	: impossible" << std::endl;
		std::cout << "int	: impossible" << std::endl;
		std::cout << "float	: impossible" << std::endl;
		std::cout << "double	: impossible" << std::endl;
	}
}

