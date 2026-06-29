/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:29:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/29 12:32:15 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    Implement the following functions:
        Base * generate(void);
            It randomly instantiates A, B, or C and returns the instance as a Base pointer. 
            Feel free to use anything you like for the random choice implementation.
    
    void identify(Base* p);
            It prints the actual type of the object pointed to by p: "A", "B", or "C".
    
    void identify(Base& p);
            It prints the actual type of the object referenced by p: "A", "B", or "C". 
            Using a pointer inside this function is forbidden.
            Including the typeinfo header is forbidden.
*/

#include "../include/Base.hpp"

Base::~Base() 
{    
}
