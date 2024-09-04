/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:07 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:36:48 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_HPP
# define Fixed_HPP

# include <string>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Fixed
{
	private:

		int					_raw;
		static const int	_fractionalBits = 8;

	public:

		Fixed();							// Default constructor
		Fixed(const Fixed &src);			// Copy constructor
		Fixed &operator=(const Fixed &src);	// Assignation operator
		~Fixed();							// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

void	dbgPrint(const std::string &msg);

#endif // Fixed_HPP
