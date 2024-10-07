#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(-1) {}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(-1) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	outOfRange(grade);
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

bool Bureaucrat::outOfRange(int grade) const
{
	if (grade == -1)
		throw Bureaucrat::SetGradeException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	return (false);
}