#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const &other) { (void)other; }

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			for (int j = i + 1; j < 3; ++j)
				delete forms[j];
			return forms[i];
		}
		delete forms[i];
	}
	std::cout << "Error: Form name " << formName << " not recognized." << std::endl;
	return NULL;
}
