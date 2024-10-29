#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat john("John", 1);
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 150);

		ShrubberyCreationForm shrubbery("Home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "\n--- Testing Signing ---\n" << std::endl;
		john.signForm(shrubbery);
		alice.signForm(robotomy);
		bob.signForm(pardon);  // This should fail

		std::cout << "\n--- Testing Execution ---\n" << std::endl;
		john.executeForm(shrubbery);
		alice.executeForm(robotomy);
		john.executeForm(pardon);

		std::cout << "\n--- Testing Failure Cases ---\n" << std::endl;
		bob.executeForm(shrubbery);  // This should fail due to low grade
		alice.executeForm(pardon);   // This should fail since not signed
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
