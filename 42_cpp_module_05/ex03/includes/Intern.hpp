#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target) const;
};

#endif // INTERN_HPP
