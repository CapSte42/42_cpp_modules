#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const name) : _name(name.empty() ? "default" : name), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	outOfRange(grade);
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name), _grade(other._grade) {}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	std::cout << "Attribute name is const, so it cannot be copied" << std::endl;
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	outOfRange(grade);
	_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	outOfRange(_grade - 1);
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	outOfRange(_grade + 1);
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	outOfRange(_grade);
	if (form.getSigned())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because it is already signed" << std::endl;
		return ;
	}
	if (_grade > form.getGradeToSign())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because grade is too low" << std::endl;
		return ;
	}
	form.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::outOfRange(int grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

