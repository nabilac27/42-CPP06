/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:02:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/11 23:08:55 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <climits>
# include <cfloat>
# include <iomanip>
# include <cctype>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID
};

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& other);
	
	static bool		isPseudoLiteral(const std::string& input);
	static bool		isChar(const std::string& input);
	static bool		isInt(const std::string& input);
	static bool		isFloat(const std::string& input);
	static bool		isDouble(const std::string& input);
	static e_type	checkType(const std::string& input);
	
	static void		printPseudoLiteral(const std::string& input);
	static void		printChar(char c);
	static void		printNumber(double value);
		
  public:
	static void		convert(const std::string &input);
};

#endif
