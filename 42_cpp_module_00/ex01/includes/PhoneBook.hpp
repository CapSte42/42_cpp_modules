/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:12:32 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 14:29:41 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			_contacts[8];
		static int		_nbContacts;
		int				_index;

	public:
		PhoneBook();
		~PhoneBook();

	// setters
	void			setContact(const Contact &contact);
	void			setIndex(int index);
	void			setNbContacts(int nbContacts);

	// getters
	Contact			*getContacts();
	int				getIndex() const;
	int				getNbContacts() const;

	// member functions
	void			add();
	void			search();
	void			autofill();
};

void	handleEof(std::istream &inputStream);

#endif
