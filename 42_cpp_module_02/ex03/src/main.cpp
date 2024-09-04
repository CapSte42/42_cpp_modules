/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:10 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 16:35:04 by smontuor         ###   ########.fr       */
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

	Point p1(5.0f, 5.0f);
	Point p2(10.0f, 10.0f);
	Point p3(0.0f, 0.0f);
	Point p4(5.0f, 0.0f);

	std::cout << "p1 is inside triangle ABC: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "p2 is inside triangle ABC: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "p3 is inside triangle ABC: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "p4 is inside triangle ABC: " << bsp(a, b, c, p4) << std::endl;

	return 0;
}
