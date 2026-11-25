/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 02:49:58 by grivault          #+#    #+#             */
/*   Updated: 2026/11/25 03:05:17 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}
