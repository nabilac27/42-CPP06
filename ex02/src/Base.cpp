/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:29:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 02:57:28 by nchairun         ###   ########.fr       */
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
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

/* ************************************************************************** */
/*  ORTHODOX CANONICAL FORM                                                   */
/* ************************************************************************** */
// Base::Base()
// {
//     std::cout << " [Base] Default constructor called" << std::endl;
// }

// Base::Base(const Base& other)
// {
//     (void)other;
//     std::cout << " [Base] Copy constructor called" << std::endl;
// }

// Base& Base::operator=(const Base& other)
// {
//     (void)other;
//     std::cout << " [Base] Copy assignment operator called" << std::endl;
//     return (*this);
// }

Base::~Base()
{
    // std::cout << " [Base] Destructor called" << std::endl;
}

/* ************************************************************************** */
/*  GENERATE                                                                  */
/* ************************************************************************** */

Base* generate(void)
{
	int	type;

	type = rand() % 3;
	type = 0;

	std::cout << " [Debug] Random value: " << type << std::endl;
	
	if (type == 0)
		return (new A);
	if (type == 1)
		return (new B);
	return (new C);
}

/* ************************************************************************** */
/*  IDENTIFY                                                                  */
/* ************************************************************************** */

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		(void)e;
	}

	std::cout << "Unknown" << std::endl;
}