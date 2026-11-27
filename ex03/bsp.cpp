/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 03:50:16 by grivault          #+#    #+#             */
/*   Updated: 2026/11/27 04:06:29 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	cross(Point const a, Point const b, Point const point)
{
	Fixed	result((b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX()));

	return (result);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = cross(a, b, point);
	Fixed	d2 = cross(b, c, point);
	Fixed	d3 = cross(c, a, point);

	if ((d1 < 0 && d2 < 0 && d3 < 0) || (d1 > 0 && d2 > 0 && d3 > 0))
		return (true);
	return (false);
}
