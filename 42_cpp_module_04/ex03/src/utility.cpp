/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:19:43 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 20:27:30 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utility.hpp"
#include <iostream>

void	dbgprint(std::string color, std::string msg)
{
	if (DEBUG == 1)
		std::cout << color << msg << RESET << std::endl;
}
		
void	print(std::string color, std::string msg)
{
	std::cout << color << msg << RESET << std::endl;
}
