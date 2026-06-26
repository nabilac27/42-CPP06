/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:02:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/26 23:48:50 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &other);

  public:
	static void convert(const std::string &input);
};

#endif
