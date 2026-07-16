/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:26:56 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/16 19:56:57 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// int main(void)
// {
// 	std::srand(static_cast<unsigned int>(std::time(NULL)));

// 	/* ************************************************************************** */
// 	/*  RANDOM TEST                                                              */
// 	/* ************************************************************************** */

// 	std::cout << "======================================" << std::endl;
// 	std::cout << "             Random Test" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	Base* randomObject = generate();

// 	std::cout << "Pointer   : ";
// 	identify(randomObject);

// 	std::cout << "Reference : ";
// 	identify(*randomObject);

// 	delete randomObject;

// 	/* ************************************************************************** */
// 	/*  EXPLICIT TYPE TESTS                                                       */
// 	/* ************************************************************************** */

// 	std::cout << std::endl;
// 	std::cout << "======================================" << std::endl;
// 	std::cout << "          Explicit Type Tests" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	Base* cBase = new C;

// 	std::cout << "C pointer : ";
// 	identify(cBase);

// 	std::cout << "C ref     : ";
// 	identify(*cBase);

// 	delete cBase;

// 	/* ************************************************************************** */
// 	/*  NULL TEST                                                                */
// 	/* ************************************************************************** */

// 	std::cout << std::endl;
// 	std::cout << "======================================" << std::endl;
// 	std::cout << "              NULL Test" << std::endl;
// 	std::cout << "======================================" << std::endl;

// 	identify(NULL);

// 	return (0);
// }

/* **************************** */

#include <iostream>

class Base
{
public:
	virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};

int main(void)
{
	Base* ptr = new A;

	std::cout << "======================================" << std::endl;
	std::cout << "Pointer (dynamic_cast)" << std::endl;
	std::cout << "======================================" << std::endl;

	A* aPtr = dynamic_cast<A*>(ptr);         // check if ptr really points to an A

	if (aPtr != NULL)
        std::cout << "A* : Success" << std::endl;
    else
    {
        std::cout << "A* : Failed (NULL)" << std::endl;
    }


	std::cout << "======================================" << std::endl;
	std::cout << "Reference (dynamic_cast)" << std::endl;
	std::cout << "======================================" << std::endl;

	Base& ref = *ptr;
    /*
        Pointer type : Base*
        Real object  : A
    */

	try
	{
		A& aRef = dynamic_cast<A&>(ref);    // check if the object referred to by ref really a A
		(void)aRef;
		std::cout << "A& : Success" << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "A& : Failed" << std::endl;
	}


	delete ptr;

	return (0);
}