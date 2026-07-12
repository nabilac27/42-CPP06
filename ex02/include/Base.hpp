/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:07:46 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 18:53:29 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <exception>
# include <iostream>

class Base
{
  public:
	// Base();
	// Base(const Base& other);
	// Base& operator=(const Base& other);
	virtual ~Base();
};

Base*   generate(void);
void	identify(Base*  p);
void	identify(Base&  p);

#endif