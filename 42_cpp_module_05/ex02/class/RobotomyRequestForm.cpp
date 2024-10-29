#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "* Drilling noises *" << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy of " << _target << " failed." << std::endl;
}
