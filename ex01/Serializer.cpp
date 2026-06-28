/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:51:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/28 14:19:47 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*  ORTHODOX CANONICAL FORM                                                   */
/* ************************************************************************** */

// Private default constructor (class cannot be instantiated)
Serializer::Serializer()
{
}

// Copy constructor (unused because all functions are static)
Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

// Copy assignment operator (unused because all functions are static)
Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

// Private destructor (class cannot be instantiated)
Serializer::~Serializer()
{
}

/* ************************************************************************** */
/*  SERIALIZE                                                                 */
/* ************************************************************************** */

// Convert a Data pointer into an integer (memory address)
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Convert the integer back into the original Data pointer
Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

