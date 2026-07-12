/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:26:56 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 19:23:49 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	/* ************************************************************************** */
	/*  SIMPLE RANDOM TEST                                                        */
	/* ************************************************************************** */

	std::cout << "======================================" << std::endl;
	std::cout << "        Single Random Object" << std::endl;
	std::cout << "======================================" << std::endl;

	Base* randomObject = generate();

	std::cout << "Pointer   : ";
	identify(randomObject);

	std::cout << "Reference : ";
	identify(*randomObject);

	delete randomObject;

	/* ************************************************************************** */
	/*  A - UPCASTING AND DOWNCASTING                                             */
	/* ************************************************************************** */

	std::cout << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "              A Test" << std::endl;
	std::cout << "======================================" << std::endl;

	A* aObject 	= new A;
	Base* aBase = aObject; 					// Upcasting: A* -> Base*

	// std::cout << "Upcast    : A* -> Base*" << std::endl;
	std::cout << "Identify  : ";
	identify(aBase);

	A* aRestored = dynamic_cast<A*>(aBase); // Downcasting: Base* -> A*

	if (aRestored)
		std::cout << "Downcast  : Base* -> A* successful" << std::endl;
	else
		std::cout << "Downcast  : Base* -> A* failed" << std::endl;

	delete aBase;

	/* ************************************************************************** */
	/*  B - UPCASTING AND DOWNCASTING                                             */
	/* ************************************************************************** */

	std::cout << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << "              B Test" << std::endl;
	std::cout << "======================================" << std::endl;

	B* bObject = new B;
	Base* bBase = bObject; // Upcasting: B* -> Base*

	// std::cout << "Upcast    : B* -> Base*" << std::endl;
	std::cout << "Identify  : ";
	identify(bBase);

	B* bRestored = dynamic_cast<B*>(bBase); // Downcasting: Base* -> B*

	if (bRestored)
		std::cout << "Downcast  : Base* -> B* successful" << std::endl;
	else
		std::cout << "Downcast  : Base* -> B* failed" << std::endl;

	delete bBase;

	return (0);
}

/*
	The destructor is virtual for two reasons:

	It makes Base polymorphic, which allows dynamic_cast to work.
	It allows correct deletion through a Base*.
	Base* object = new A;
	delete object;
*/