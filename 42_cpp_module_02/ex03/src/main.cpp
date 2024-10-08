/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:10 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 16:27:11 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main()
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	Point p1(5.0f, 5.0f);		// Inside ABC
	Point p2(10.0f, 10.0f);	// Outside ABC
	Point p3(0.0f, 0.0f);		// On A
	Point p4(5.0f, 0.0f);		// On AB
	Point p5(5.0f, 10.0f);	// On AC

	std::cout << "p1 is inside triangle ABC: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 is inside triangle ABC: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 is inside triangle ABC: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4 is inside triangle ABC: " << bsp(a, b, c, p4) << std::endl;
	std::cout << "p5 is inside triangle ABC: " << bsp(a, b, c, p5) << std::endl;

	return 0;
}
