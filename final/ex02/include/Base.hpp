/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:07:46 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/16 16:06:55 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <exception>
# include <iostream>
# include <ctime>


class Base
{
  public:
    virtual ~Base();
};

Base* generate(void);
void	identify(Base*  p);
void	identify(Base&  p);

#endif