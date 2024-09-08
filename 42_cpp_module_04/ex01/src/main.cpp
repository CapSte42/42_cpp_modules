/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor42 <smontuor42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:49:25 by smontuor42        #+#    #+#             */
/*   Updated: 2024/09/08 18:47:15 by smontuor42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

#include <iostream>

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		// to access the getBrain() method, we need to cast the Animal pointer to a Dog pointer
		// or a Cat pointer
		// this is called downcasting
		// we need to do this because the getBrain() method is not declared in the Animal class
		// but in the Dog and Cat classes
		const Dog* dog = static_cast<const Dog*>(j);
		const Cat* cat = static_cast<const Cat*>(i);

		Brain* dogBrain = dog->getBrain();
		Brain* catBrain = cat->getBrain();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();

		dogBrain->setIdea(0, "Chase the ball!");
		catBrain->setIdea(0, "Climb a tree!");

		std::cout << "Dog's first idea: " << dogBrain->getIdea(0) << std::endl;
		std::cout << "Cat's first idea: " << catBrain->getIdea(0) << std::endl;

		// deep copy of the Dog and Cat objects
		Dog dogCopy = *dog;
		Cat catCopy = *cat;

		dogCopy.getBrain()->setIdea(0, "Fetch the stick!");
		catCopy.getBrain()->setIdea(0, "Catch the mouse!");

		std::cout << "Original Dog's idea: " << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Dog's idea: " << dogCopy.getBrain()->getIdea(0) << std::endl;

		std::cout << "Original Cat's idea: " << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "Copied Cat's idea: " << catCopy.getBrain()->getIdea(0) << std::endl;

		delete j;
		delete i;
	}

}