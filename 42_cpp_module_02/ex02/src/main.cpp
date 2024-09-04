/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:17:10 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/03 17:33:44 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>


int main(void)
{
	std::cout << "Test costruttori" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c(10);
	Fixed const d(42.42f);
	Fixed const e(b);

	std::cout << "Test output stream overload e conversione a float" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;

	std::cout << "Test operatori di incremento" << std::endl;
	std::cout << "Pre-incremento a: " << ++a << std::endl;
	std::cout << "Post-incremento a: " << a++ << std::endl;
	std::cout << "Valore di a dopo post-incremento: " << a << std::endl;

	std::cout << "Test operatori di decremento" << std::endl;
	std::cout << "Pre-decremento a: " << --a << std::endl;
	std::cout << "Post-decremento a: " << a-- << std::endl;
	std::cout << "Valore di a dopo post-decremento: " << a << std::endl;

	std::cout << "Test operatori aritmetici" << std::endl;
	Fixed resultAdd = c + d;
	Fixed resultSub = c - d;
	Fixed resultMul = c * d;
	Fixed resultDiv = c / d;

	std::cout << "c + d: " << resultAdd << std::endl;
	std::cout << "c - d: " << resultSub << std::endl;
	std::cout << "c * d: " << resultMul << std::endl;
	std::cout << "c / d: " << resultDiv << std::endl;

	std::cout << "Test operatori di confronto" << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c >= d: " << (c >= d) << std::endl;
	std::cout << "c <= d: " << (c <= d) << std::endl;
	std::cout << "c == d: " << (c == d) << std::endl;
	std::cout << "c != d: " << (c != d) << std::endl;

	std::cout << "Test min e max" << std::endl;
	std::cout << "Max tra c e d: " << Fixed::max(c, d) << std::endl;
	std::cout << "Min tra c e d: " << Fixed::min(c, d) << std::endl;
	std::cout << "Max tra a e b: " << Fixed::max(a, b) << std::endl;
	std::cout << "Min tra a e b: " << Fixed::min(a, b) << std::endl;

	std::cout << "Test setRawBits e getRawBits" << std::endl;
	std::cout << "Raw bits di a: " << a.getRawBits() << std::endl;
	a.setRawBits(256);
	std::cout << "Raw bits di a dopo set: " << a.getRawBits() << std::endl;

	return 0;
}

