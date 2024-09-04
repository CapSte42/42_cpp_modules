/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:10:14 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 14:33:18 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <cstdio>
#include <string>

// Static member initialization
int	PhoneBook::_nbContacts = 0;

// Default constructor and destructor
PhoneBook::PhoneBook() : _index(0) {}
PhoneBook::~PhoneBook() {}

// Setters
void	PhoneBook::setIndex(int index)					{ _index = index; }
void	PhoneBook::setNbContacts(int nbContacts)		{ _nbContacts = nbContacts; }
void	PhoneBook::setContact(const Contact &contact)
{
	if (_nbContacts < 8)
	{
		_contacts[_nbContacts] = contact;
		_nbContacts++;
	}
	else
	{
		std::cout << "Phone book is full." << std::endl;
		std::cout << "The oldest contact will be eliminated." << std::endl;
		for (int i = 0; i < 7; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[7] = contact;
	}
}


// Getters
Contact	*PhoneBook::getContacts()			{ return _contacts; }
int		PhoneBook::getIndex()		const	{ return _index; }
int		PhoneBook::getNbContacts()	const	{ return _nbContacts; }

// Member functions
void	PhoneBook::add()
{
	Contact	contact;
	std::string input;
	typedef void (Contact::*setFunction)(const std::string &);
	const std::string fields[5] = {
		"First name",
		"Last name",
		"Nickname",
		"Phone number",
		"Darkest secret"
	};
	setFunction	values[5] = {
		&Contact::setFirstName,
		&Contact::setLastName,
		&Contact::setNickname,
		&Contact::setPhoneNumber,
		&Contact::setDarkestSecret
	};

	for (int i = 0; i < 5; i++)
	{
		std::cin.clear();
		std::cout << fields[i] << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			handleEof(std::cin);
			input.clear();
			i--;
			continue;
		}
		(contact.*values[i])(input);
	}
	this->setContact(contact);
	this->setIndex(this->getNbContacts() + 1);
}

void	PhoneBook::search()
{
	Contact	*contacts = this->getContacts();
	int		nbContacts = this->getNbContacts();
	typedef void (Contact::*getFunction)() const;
	getFunction	values[3] = {
		&Contact::getTrunkFirstName,
		&Contact::getTrunkLastName,
		&Contact::getTrunkNickName
	};

	if (nbContacts == 0)
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	std::cout << "Index-----|First-Name|Last--Name|Nickname--" << std::endl;
	for (int i = 0; i < nbContacts; i++)
	{
		std::cout << i + 1 << "---------|";
		for (int j = 0; j < 3; j++)
		{
			(contacts[i].*values[j])();
			j < 2 ? std::cout << "|" : std::cout << std::endl;
		}
	}
	select:
	std::cout << "Enter an index: ";
	int index;
	std::cin >> index;
	if (std::cin.fail() || index < 1 || index > nbContacts)
	{
		std::cout << "Invalid index." << std::endl;
		handleEof(std::cin);
		goto select;
	}
	contacts[index - 1].display();
	handleEof(std::cin);
}

void	PhoneBook::autofill()
{
	Contact	contact[8] = {
		Contact("John", "Doe", "JD", "1234567890", "I am John Doe."),
		Contact("Jane", "Doe", "Jane", "0987654321", "I am Jane Doe."),
		Contact("John", "Smith", "Smithy", "1231231234", "I am John Smith."),
		Contact("Jane", "Smith", "Janey", "3213214321", "I am Jane Smith."),
		Contact("John", "Johnson", "JJ", "1112223333", "I am John Johnson."),
		Contact("Jane", "Johnson", "JJ", "3332221111", "I am Jane Johnson."),
		Contact("John", "Doe", "JD", "1234567890", "I am John Doe."),
		Contact("Jane", "Doe", "Jane", "0987654321", "I am Jane Doe.")
	};

	for (int i = 0; i < 8; i++)
		this->setContact(contact[i]);
	this->setIndex(8);
	std::cout << "Phone book autofilled." << std::endl;
}

void	handleEof(std::istream &inputStream)
{
	char	c;

	inputStream.clear();
	while (inputStream.get(c) && c != '\n');
	clearerr(stdin);
	std::cout << std::endl;
}
