/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:52:46 by smontuor          #+#    #+#             */
/*   Updated: 2024/08/30 20:19:51 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEPROCESSOR_HPP
# define FILEPROCESSOR_HPP

# include <string>

class	FileProcessor
{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;

		std::string		_readFile() const;
		std::string		_replaceOccurences(std::string &content) const;
		void			_writeFile(const std::string &content) const;

	public:
		FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2);
		void			process();
};

#endif
