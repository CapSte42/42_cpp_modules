#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << "        _-_" << std::endl;
		file << "     /~~   ~~\\" << std::endl;
		file << "  /~~         ~~\\" << std::endl;
		file << " {               }" << std::endl;
		file << "  \\  _-     -_  /" << std::endl;
		file << "    ~ \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
		file.close();
	}
	else
	{
		std::cerr << "Error: Could not create shrubbery file" << std::endl;
	}
}
