#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("DefForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string const name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

// in this case, _gradeToSign and _gradeToExecute are const, so we can't change them after the initialization
// so we have to check if they are out of range in the initialization list
// isOutOfRange is a boolean function that returns false if the grade is in the range [1, 150]
Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
_gradeToSign(isOutOfRange(gradeToSign) ? throw GradeTooHighException() : gradeToSign),
_gradeToExecute(isOutOfRange(gradeToExecute) ? throw GradeTooHighException() : gradeToExecute) {}

Form::Form(Form const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(Form const &other)
{
	std::cout << "Some attributes are const, so they cannot be copied" << std::endl;
	_signed = other._signed;
	return (*this);
}

Form::~Form() {}

std::string const Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::setSigned(bool isSigned)
{
	_signed = isSigned;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because the grade is too low" << std::endl;
		return ;
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

bool Form::isOutOfRange(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (false);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
