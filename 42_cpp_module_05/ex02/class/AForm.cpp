#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("DefForm"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const name) : _name(name), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

// in this case, _gradeToSign and _gradeToExecute are const, so we can't change them after the initialization
// so we have to check if they are out of range in the initialization list
// isOutOfRange is a boolean function that returns false if the grade is in the range [1, 150]
AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false),
_gradeToSign(isOutOfRange(gradeToSign) ? throw GradeTooHighException() : gradeToSign),
_gradeToExecute(isOutOfRange(gradeToExecute) ? throw GradeTooHighException() : gradeToExecute) {}

AForm::AForm(AForm const &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(AForm const &other)
{
	std::cout << "Some attributes are const, so they cannot be copied" << std::endl;
	_signed = other._signed;
	return (*this);
}

AForm::~AForm() {}

std::string const AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::setSigned(bool isSigned)
{
	_signed = isSigned;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because the grade is too low" << std::endl;
		throw GradeTooLowException();
		return ;
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

bool AForm::isOutOfRange(int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (false);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
