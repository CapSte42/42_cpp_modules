/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 22:08:24 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:26:42 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string command;

	while (true)
	{
		std::cin.clear();
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			handleEof(std::cin);
			command.clear();
			continue;
		}
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			phoneBook.add();
		else if (command == "SEARCH")
			phoneBook.search();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}
