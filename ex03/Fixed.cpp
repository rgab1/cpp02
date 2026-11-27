/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 02:49:58 by grivault          #+#    #+#             */
/*   Updated: 2026/11/27 04:31:53 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
	this->_rawBits = 0;
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = (int)(roundf(value * (1 << this->_fractionalBits)));
}
Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
		this->_rawBits = other._rawBits;
    }
    return *this;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits( void ) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_rawBits = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_rawBits >> this->_fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_rawBits / (1 << this->_fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_rawBits + other._rawBits);
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->_rawBits - other._rawBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(((long)(this->_rawBits) << this->_fractionalBits) / other._rawBits);
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(((long)(this->_rawBits) * other._rawBits) >> _fractionalBits);
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	this->_rawBits++;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->_rawBits--;
	return (temp);
}

Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed&			Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}
