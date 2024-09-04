/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:19:28 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 10:25:48 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:

		Fixed const _x;
		Fixed const _y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		~Point();

		Point &operator=(const Point &src);

		Fixed const &getX(void) const;
		Fixed const &getY(void) const;
};

#endif // POINT_HPP
