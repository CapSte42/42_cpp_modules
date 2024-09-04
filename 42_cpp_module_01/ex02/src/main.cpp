/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:26:09 by smontuor          #+#    #+#             */
/*   Updated: 2024/08/07 09:23:38 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string: \t\t" << &str << std::endl;
	std::cout << "Address of the stringPTR: \t" << stringPTR << std::endl;
	std::cout << "Address of the stringREF: \t" << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "String: \t\t\t" << str << std::endl;
	std::cout << "StringPTR: \t\t\t" << *stringPTR << std::endl;
	std::cout << "StringREF: \t\t\t" << stringREF << std::endl;

	return (0);
}
