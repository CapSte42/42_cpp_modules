/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:53:06 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:33:56 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileProcessor.hpp"
#include <iostream>

static int	parse_args(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: " << av[0] << " filename s1 s2" << std::endl;
		return (1);
	}

	std::string	s1(av[2]);
	std::string	s2(av[3]);

	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (parse_args(ac, av))
		return (1);

	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	try
	{
		FileProcessor	fileProcessor(filename, s1, s2);
		fileProcessor.process();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
