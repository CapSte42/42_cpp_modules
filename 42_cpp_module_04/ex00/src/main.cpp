/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:49:25 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 17:39:35 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		meta->makeSound();
		i->makeSound();
		j->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		const WrongCat* wrongCatObject = new WrongCat();

		std::cout << "Type: " << wrongAnimal->getType() << std::endl;
		std::cout << "Type: " << wrongCat->getType() << std::endl;
		std::cout << "Type: " << wrongCatObject->getType() << std::endl;

		wrongAnimal->makeSound();
		wrongCat->makeSound();
		wrongCatObject->makeSound();

		delete wrongAnimal;
		delete wrongCat;
		delete wrongCatObject;
	}
}