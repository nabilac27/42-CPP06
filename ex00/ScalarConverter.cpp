/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:09:27 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/26 23:59:38 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

/* ************************************************************************** */
/*  ORTHODOX CANONICAL FORM                                                   */
/* ************************************************************************** */

ScalarConverter::ScalarConverter()
{ }

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter::~ScalarConverter()
{ }

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/*  CONVERT				                                                      */
/* ************************************************************************** */

bool isSpecial(const std::string& input) 
{ 
	return (input == "nan" || 
			input == "nanf" || 
			input == "+inf" || 
			input == "+inff" || 
			input == "-inf" || 
			input == "-inff"); 
}

bool isChar(const std::string& input) 
{ 
	return (input.length() == 1 && !std::isdigit(input[0])); 
}

void ScalarConverter::convert(const std::string& input) 
{ 
	std::cout << "Input: " << input << std::endl;
		
	if (isSpecial(input)) 
	{ 
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl; 
		
		if (input == "nan" || input == "nanf") 
		{ 
			std::cout << "float: nanf" << std::endl; 
			std::cout << "double: nan" << std::endl; 
		} 
		else if (input[0] == '+') 
		{ 
			std::cout << "float: +inff" << std::endl; 
			std::cout << "double: +inf" << std::endl; 
		} 
		else 
		{ 
			std::cout << "float: -inff" << std::endl; 
			std::cout << "double: -inf" << std::endl; 
		} 
		return; 
	} 
	if (isChar(input)) 
	{ 
		char c = input[0]; 
		std::cout << "char: '" << c << "'" << std::endl; 
		std::cout << "int: " << static_cast<int>(c) << std::endl; 
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl; 
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; 
		return; 
	} 
	std::cout << "Normal number conversion will be implemented next" << std::endl; 
}