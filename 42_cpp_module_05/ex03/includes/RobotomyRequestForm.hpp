#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();

		virtual void execute(Bureaucrat const &executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
