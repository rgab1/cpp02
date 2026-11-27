/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 04:07:05 by grivault          #+#    #+#             */
/*   Updated: 2026/11/27 04:07:16 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static void runTest(const char* name, Point const& a, Point const& b,
                    Point const& c, Point const& p, bool expected)
{
	bool result = bsp(a, b, c, p);
	std::cout << name << ": "
	          << (result ? "true" : "false")
	          << " (expected " << (expected ? "true" : "false") << ") -> "
	          << (result == expected ? "[OK]" : "[KO]")
	          << std::endl;
}

int main(void)
{
	// Standard triangle: (0,0), (10,0), (0,10)
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	std::cout << "=== Standard Triangle (CCW) ===" << std::endl;
	runTest("Strictly inside (2, 2)",       a, b, c, Point(2.0f, 2.0f),   true);
	runTest("Strictly inside (0.1, 0.1)",   a, b, c, Point(0.1f, 0.1f),   true);
	runTest("Strictly outside (10, 10)",    a, b, c, Point(10.0f, 10.0f), false);
	runTest("Strictly outside (-1, 2)",     a, b, c, Point(-1.0f, 2.0f),  false);
	runTest("On vertex A (0, 0)",           a, b, c, Point(0.0f, 0.0f),   false);
	runTest("On vertex B (10, 0)",          a, b, c, Point(10.0f, 0.0f),  false);
	runTest("On bottom edge (5, 0)",        a, b, c, Point(5.0f, 0.0f),   false);
	runTest("On hypotenuse (5, 5)",         a, b, c, Point(5.0f, 5.0f),   false);

	std::cout << "\n=== Same Triangle Reversed (CW) ===" << std::endl;
	runTest("Strictly inside CW (2, 2)",    a, c, b, Point(2.0f, 2.0f),   true);
	runTest("On hypotenuse CW (5, 5)",      a, c, b, Point(5.0f, 5.0f),   false);

	std::cout << "\n=== Negative & Float Coordinates ===" << std::endl;
	Point n1(-5.5f, -5.5f);
	Point n2(5.5f, -5.5f);
	Point n3(0.0f, 5.5f);
	runTest("Inside negative triangle (0, 0)",   n1, n2, n3, Point(0.0f, 0.0f),   true);
	runTest("Outside negative triangle (0, -6)", n1, n2, n3, Point(0.0f, -6.0f),  false);
	runTest("On edge (-2.75, 0)",                n1, n2, n3, Point(-2.75f, 0.0f), false);

	std::cout << "\n=== Degenerate Triangle (Collinear) ===" << std::endl;
	Point d1(0.0f, 0.0f);
	Point d2(5.0f, 5.0f);
	Point d3(10.0f, 10.0f);
	runTest("Point on collinear line (2, 2)", d1, d2, d3, Point(2.0f, 2.0f), false);

	return (0);
}
