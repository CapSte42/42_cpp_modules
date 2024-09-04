/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 16:23:15 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <iostream>
# include <cmath>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Fixed
{
	private:

		int					_raw;
		static const int	_fractionalBits = 8;

	public:
/*-------------------------- Constructors --------------------------------------*/
//	Default constructor
//	Copy constructor
//	Int constructor
//	Float constructor
//	Destructor
/*------------------------------------------------------------------------------*/
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

/*-------------------------- Operators -----------------------------------------*/
//	Overload operator = (assignation)
//	Overload operator > (greater than)
//	Overload operator < (less than)
//	Overload operator >= (greater than or equal to)
//	Overload operator <= (less than or equal to)
//	Overload operator == (equal to)
//	Overload operator != (not equal to)
/*------------------------------------------------------------------------------*/
		Fixed &operator=(const Fixed &src);
		bool operator>(const Fixed &src) const;
		bool operator<(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;

/*-------------------------- Getters & Setters -------------------------------- */
//	getRawBits
//	setRawBits
/*------------------------------------------------------------------------------*/
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

/*-------------------------- Member functions --------------------------------- */
//	toInt
//	toFloat
/*------------------------------------------------------------------------------*/
		float	toFloat(void) const;
		int		toInt(void) const;

/*-------------------------- Arithmetic operators ------------------------------*/
//	Overload operator + (addition)
//	Overload operator - (subtraction)
//	Overload operator * (multiplication)
//	Overload operator / (division)
/*------------------------------------------------------------------------------*/
		Fixed operator+(const Fixed &src) const;
		Fixed operator-(const Fixed &src) const;
		Fixed operator*(const Fixed &src) const;
		Fixed operator/(const Fixed &src) const;

/*-------------------------- Increment & Decrement -----------------------------*/
//	Overload operator ++ (pre-increment)
//	Overload operator ++ (post-increment)
//	Overload operator -- (pre-decrement)
//	Overload operator -- (post-decrement)
/*------------------------------------------------------------------------------*/
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

/*-------------------------- Static member functions ---------------------------*/
//	min
//	max
//  const min
//  const max
/*------------------------------------------------------------------------------*/
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		Fixed abs(void) const;
};

void	dbgPrint(const std::string &msg);

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // Fixed_HPP
