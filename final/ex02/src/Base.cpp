/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:29:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/16 15:58:34 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

/* ************************************************************************** */
/*  VIRTUAL DESTRUCTOR		                                                  */
/* ************************************************************************** */
Base::~Base()
{
}

/* ************************************************************************** */
/*  GENERATE                                                                  */
/* ************************************************************************** */

Base* generate(void)
{
	int	randNumber;

	randNumber = rand() % 3;

	// std::cout << " [Debug] Random value: " << randNumber << std::endl;
	
	if (randNumber == 0)
		return (new A);
	if (randNumber == 1)
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