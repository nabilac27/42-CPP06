/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CheckType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:44:13 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/11 23:36:00 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

/* ************************************************************************** */
/* 	CHECK TYPE                                                                */
/* ************************************************************************** */
e_type ScalarConverter::checkType(const std::string& input)
{
	if (isPseudoLiteral(input))
		return (PSEUDO);
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
/*	PSEUDO-LITERAL                                                            */
/* ************************************************************************** */
bool ScalarConverter::isPseudoLiteral(const std::string& input)
{
	return (input == "nan" || input == "nanf" || input == "+inf"
		|| input == "+inff" || input == "-inf" || input == "-inff");
}

void ScalarConverter::printPseudoLiteral(const std::string &input)
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


/* ************************************************************************** */
/*	CHAR                                                        			  */
/* ************************************************************************** */
bool ScalarConverter::isChar(const std::string &input)
{
    if (input.length() != 1)
        return (false);
    if (std::isdigit(static_cast<unsigned char>(input[0])))
        return (false);

    return (true);
}

void ScalarConverter::printChar(char c)
{
	std::cout << "char	: '" 	<< c << "'" 				<< std::endl;
	std::cout << "int	: " 	<< static_cast<int>(c) 		<< std::endl;
	
	std::cout << std::fixed 	<< std::setprecision(1);
	std::cout << "float	: " 	<< static_cast<float>(c) 	<< "f" 			<< std::endl;
	std::cout << "double	: " << static_cast<double>(c)	<< std::endl;
}


/* ************************************************************************** */
/*	NUMBER	                                                    			  */
/* ************************************************************************** */
bool ScalarConverter::isInt(const std::string& input)
{
	size_t	i;

	i = 0;
	if (input.empty())
        return (false);
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == input.length())
		return (false);
	while (i < input.length())
	{
		if (!(std::isdigit(input[i])))
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
	
	if (input.empty())
    	return (false);
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
	std::string valueWithoutF;
	
	if (input.length() < 2)
		return (false);
	if (input[input.length() - 1] != 'f')
		return (false);
	valueWithoutF = input.substr(0, input.length() - 1); // input string after removing the final f."
	return (isDouble(valueWithoutF));
}


void ScalarConverter::printNumber(double value)
{
	/****** CHAR ******/
	if (value < 0 || value > 127)
		std::cout	 << "char	: impossible"
					 << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout	 << "char	: Non displayable"	
		 		  	 << std::endl;
	else
		std::cout 	<< "char	: '" 					
				 	<< static_cast<char>(value) 
				 	<< "'" 
				 	<< std::endl;
	
	/****** INT ******/
	if (value < INT_MIN || value > INT_MAX)
		std::cout 	<< "int	: impossible" 
				  	<< std::endl;
	else
		std::cout 	<< "int	: " 
					<< static_cast<int>(value) 
					<< std::endl;
					
	/****** FLOAT ******/
	std::cout << std::fixed << std::setprecision(1);
	if (value > FLT_MAX || value < -FLT_MAX)
		std::cout	<< "float	: impossible" 
				 	<< std::endl;
	else
		std::cout 	<< "float	: " << static_cast<float>(value) 
					<< "f" << std::endl;
	
	/****** DOUBLE ******/
	std::cout 		<< "double	: " 
					<< value 
					<< std::endl;
}

