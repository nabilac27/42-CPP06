/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:51:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/07/12 02:26:04 by nchairun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*  ORTHODOX CANONICAL FORM                                                   */
/* ************************************************************************** */

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
}

/* ************************************************************************** */
/*  SERIALIZE, DESERIALIZE                                                    */
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

