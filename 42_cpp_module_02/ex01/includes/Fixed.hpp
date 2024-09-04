/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/01 15:55:16 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Fixed
{
	private:

		int					_raw;
		static const int	_fractionalBits = 8;

	public:
		// Constructors
		Fixed();								// Default constructor
		Fixed(const Fixed &src);				// Copy constructor
		Fixed(const int value);					// Int constructor
		Fixed(const float value);				// Float constructor
		// Overloads operators
		Fixed &operator=(const Fixed &src);		// Overload operator = (assignation)
		// Destructor
		~Fixed();								// Destructor
		// set/get
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		// Methods
		float	toFloat(void) const;
		int		toInt(void) const;
};

void	dbgPrint(const std::string &msg);

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);	// Overload operator << (left shift)

#endif // Fixed_HPP
