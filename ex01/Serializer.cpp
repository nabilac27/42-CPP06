/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 13:51:26 by nchairun          #+#    #+#             */
/*   Updated: 2026/06/28 13:51:43 by nchairun         ###   ########.fr       */
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