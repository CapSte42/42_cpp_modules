/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:19:01 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 16:26:52 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

static Fixed area(const Point &p1, const Point &p2, const Point &p3)
{
	return Fixed(0.5f) * (p1.getX() * (p2.getY() - p3.getY()) +
				  p2.getX() * (p3.getY() - p1.getY()) +
				  p3.getX() * (p1.getY() - p2.getY())).abs();
}

static bool isCollinear(const Point &p1, const Point &p2, const Point &p3)
{
	return area(p1, p2, p3) == Fixed(0);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	if (point == a || point == b || point == c)
		return false;

	if (isCollinear(a, b, point) || isCollinear(b, c, point) || isCollinear(c, a, point))
		return false;

	Fixed totalArea = area(a, b, c);

	Fixed area1 = area(a, b, point);
	Fixed area2 = area(b, c, point);
	Fixed area3 = area(c, a, point);

	return totalArea == area1 + area2 + area3;
}
