/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:59:47 by smontuor          #+#    #+#             */
/*   Updated: 2024/08/07 11:27:31 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		Contact(
			const std::string &firstName,
			const std::string &lastName,
			const std::string &nickName,
			const std::string &phoneNumber,
			const std::string &darkestSecret
			);
		~Contact();

	// setters
	void			setFirstName(const std::string &firstName);
	void			setLastName(const std::string &lastName);
	void			setNickname(const std::string &nickName);
	void			setPhoneNumber(const std::string &phoneNumber);
	void			setDarkestSecret(const std::string &darkestSecret);

	// getters
	std::string		getFirstName() const;
	std::string		getLastName() const;
	std::string		getNickName() const;
	std::string		getPhoneNumber() const;
	std::string		getDarkestSecret() const;

	// truncated getters
	void			getTrunkFirstName() const;
	void			getTrunkLastName() const;
	void			getTrunkNickName() const;

	// member functions
	void			display() const;

	// assignment operator
	Contact			&operator=(const Contact &other);
};

#endif
