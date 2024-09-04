/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileProcessor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smontuor <smontuor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 07:52:59 by smontuor          #+#    #+#             */
/*   Updated: 2024/09/04 12:33:49 by smontuor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileProcessor.hpp"
#include <fstream>

FileProcessor::FileProcessor(const std::string &filename, const std::string &s1, const std::string &s2) : _filename(filename), _s1(s1), _s2(s2) {}

std::string	FileProcessor::_readFile() const
{
	std::ifstream	file(_filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not open file");

	std::string	content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	return content;
}

std::string	FileProcessor::_replaceOccurences(std::string &content) const
{
	std::string		newContent;
	size_t			pos = 0;
	size_t			foundPos;

	while ((foundPos = content.find(_s1, pos)) != std::string::npos)
	{
		newContent.append(content, pos, foundPos - pos);
		newContent.append(_s2);
		pos = foundPos + _s1.length();
	}
	newContent.append(content, pos, std::string::npos);
	return newContent;
}

void	FileProcessor::_writeFile(const std::string &content) const
{
	std::string		outFilename = _filename + ".replace";
	std::ofstream	outFile(outFilename.c_str());

	if (!outFile.is_open())
		throw std::runtime_error("Could not open file");
	outFile << content;
	outFile.close();
}

void	FileProcessor::process()
{
	std::string content = _readFile();
	std::string newContent = _replaceOccurences(content);
	_writeFile(newContent);
}
