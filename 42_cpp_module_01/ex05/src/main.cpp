/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:02:11 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:34:36 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>

int main(void)
{
	Harl	harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");

	std::cout << "[ INFO ]" << std::endl;
	harl.complain("INFO");

	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("WARNING");

	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("ERROR");

	std::cout << "[ UNKNOWN ]" << std::endl;
	harl.complain("UNKNOWN");

	return 0;
}