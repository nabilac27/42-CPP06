/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:02:19 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/26 13:10:19 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
  private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter(void);
	ScalarConverter &operator=(ScalarConverter const &value);

  public:
	static void convert(const std::string &str);
};

#endif
