/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:09:55 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:12:09 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include <iostream>

// Default constructor and destructor
Contact::Contact() {}
Contact::~Contact() {}

// Constructor with parameters
Contact::Contact(
	const std::string &firstName,
	const std::string &lastName,
	const std::string &nickName,
	const std::string &phoneNumber,
	const std::string &darkestSecret
	) :
	_firstName(firstName),
	_lastName(lastName),
	_nickName(nickName),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
	return ;
}

// Setters
void	Contact::setFirstName(const std::string &firstName)			{ _firstName = firstName; }
void	Contact::setLastName(const std::string &lastName)			{ _lastName = lastName; }
void	Contact::setNickname(const std::string &nickName)			{ _nickName = nickName; }
void	Contact::setPhoneNumber(const std::string &phoneNumber)		{ _phoneNumber = phoneNumber; }
void	Contact::setDarkestSecret(const std::string &darkestSecret)	{ _darkestSecret = darkestSecret; }

// Getters
std::string	Contact::getFirstName() 		const	{ return _firstName; }
std::string	Contact::getLastName() 			const	{ return _lastName; }
std::string	Contact::getNickName() 			const	{ return _nickName; }
std::string	Contact::getPhoneNumber() 		const	{ return _phoneNumber; }
std::string	Contact::getDarkestSecret() 	const	{ return _darkestSecret; }

// Display truncated contact information
void	Contact::getTrunkFirstName() 		const { std::string trunk = _firstName; trunk.resize(10, ' '); std::cout << trunk; }
void	Contact::getTrunkLastName() 		const { std::string trunk = _lastName; trunk.resize(10, ' '); std::cout << trunk; }
void	Contact::getTrunkNickName() 		const { std::string trunk = _nickName; trunk.resize(10, ' '); std::cout << trunk; }

// Member functions
void	Contact::display() const
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
// Assignment operator
Contact		&Contact::operator=(const Contact &pippo)
{
	_firstName = pippo.getFirstName();
	_lastName = pippo.getLastName();
	_nickName = pippo.getNickName();
	_phoneNumber = pippo.getPhoneNumber();
	_darkestSecret = pippo.getDarkestSecret();
	return *this;
}
