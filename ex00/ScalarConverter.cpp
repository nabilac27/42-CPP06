/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:09:27 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/28 13:44:18 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
/*  CHECK TYPE                                                                */
/* ************************************************************************** */

bool ScalarConverter::isSpecial(const std::string& input)
{
	return (input == "nan" || input == "nanf" || input == "+inf"
		|| input == "+inff" || input == "-inf" || input == "-inff");
}

bool ScalarConverter::isChar(const std::string &input)
{
	return (input.length() == 1 && !(std::isdigit(input[0])));
}

bool ScalarConverter::isInt(const std::string& input)
{
	size_t	i;

	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return (false);
	while (i < input.length())
	{
		if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isDouble(const std::string& input)
{
	size_t	i;
	bool	hasDot;
	bool	hasDigit;

	i 		 = 0;
	hasDot   = false;
	hasDigit = false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return (false);
	while (i < input.length())
	{
		if (input[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(input[i]))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDot && hasDigit);
}

bool ScalarConverter::isFloat(const std::string& input)
{
	std::string withoutF;
	
	if (input.length() < 2)
		return (false);
	if (input[input.length() - 1] != 'f')
		return (false);
	withoutF = input.substr(0, input.length() - 1);
	return (isDouble(withoutF));
}

e_type ScalarConverter::checkType(const std::string& input)
{
	if (isSpecial(input))
		return (SPECIAL);
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (isDouble(input))
		return (DOUBLE);
	return (INVALID);
}

/* ************************************************************************** */
/*  PRINT                                                                     */
/* ************************************************************************** */

void ScalarConverter::printSpecial(const std::string &input)
{
	std::cout << "char	: impossible" << std::endl;
	std::cout << "int	: impossible" << std::endl;
	if (input == "nan" || input == "nanf")
	{
		std::cout << "float	: nanf" 	<< std::endl;
		std::cout << "double	: nan" 	<< std::endl;
	}
	else if (input[0] == '+')
	{
		std::cout << "float	: +inff" 	<< std::endl;
		std::cout << "double	: +inf" << std::endl;
	}
	else
	{
		std::cout << "float	: -inff" 	<< std::endl;
		std::cout << "double	: -inf" << std::endl;
	}
}

void ScalarConverter::printChar(char c)
{
	std::cout << "char	: '" 	<< c << "'" 				<< std::endl;
	std::cout << "int	: " 	<< static_cast<int>(c) 		<< std::endl;
	std::cout << std::fixed 	<< std::setprecision(1);
	std::cout << "float	: " 	<< static_cast<float>(c) 	<< "f" 			<< std::endl;
	std::cout << "double	: " << static_cast<double>(c)	<< std::endl;
}

void ScalarConverter::printNumber(double value)
{
	if (value < 0 || value > 127)
		std::cout	 << "char	: impossible"
					 << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout	 << "char	: Non displayable"	
		 		  	 << std::endl;
	else
		std::cout 	<< "char: '" 					
				 	<< static_cast<char>(value) 
				 	<< "'" 
				 	<< std::endl;
	if (value < INT_MIN || value > INT_MAX)
		std::cout 	<< "int	: impossible" 
				  	<< std::endl;
	else
		std::cout 	<< "int	: " 
					<< static_cast<int>(value) 
					<< std::endl;
					
	std::cout << std::fixed << std::setprecision(1);
	std::cout << std::fixed << std::setprecision(1);
	
	if (value > FLT_MAX || value < -FLT_MAX)
		std::cout	<< "float	: impossible" 
				 	<< std::endl;
	else
		std::cout 	<< "float	: " << static_cast<float>(value) 
					<< "f" << std::endl;
					
	std::cout 		<< "double	: " 
					<< value 
					<< std::endl;
}

/* ************************************************************************** */
/*  CONVERT							                                             */
/* ************************************************************************** */

void ScalarConverter::convert(const std::string& input)
{
	e_type type;
	double value;

	type = checkType(input);

	switch (type)
	{
		case SPECIAL:
			printSpecial(input);
			break ;
		case CHAR:
			printChar(input[0]);
			break ;
		case INT:
		case FLOAT:
		case DOUBLE:
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
		break ;
	}
}