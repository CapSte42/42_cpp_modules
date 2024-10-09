#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
	// Test costruttore di default
		Bureaucrat defaultBureaucrat;
		std::cout << "Default Bureaucrat: " << defaultBureaucrat.getName() << ", Grade: " << defaultBureaucrat.getGrade() << std::endl;

	// Test costruttore con nome
		Bureaucrat bureaucrat1("Alice");
		std::cout << "Bureaucrat 1: " << bureaucrat1.getName() << ", Grade: " << bureaucrat1.getGrade() << std::endl;

	// Test costruttore con nome e grade valido
		Bureaucrat bureaucrat2("Bob", 75);
		std::cout << "Bureaucrat 2: " << bureaucrat2.getName() << ", Grade: " << bureaucrat2.getGrade() << std::endl;

	// Test incrementare e decrementare il grade
		bureaucrat2.incrementGrade();
		std::cout << "After increment: Bureaucrat 2: " << bureaucrat2.getName() << ", Grade: " << bureaucrat2.getGrade() << std::endl;

		bureaucrat2.decrementGrade();
		std::cout << "After decrement: Bureaucrat 2: " << bureaucrat2.getName() << ", Grade: " << bureaucrat2.getGrade() << std::endl;

	// Test impostare un grade troppo alto
		Bureaucrat bureaucrat3("Charlie", 0); // Questo lancerà un'eccezione
		std::cout << "Bureaucrat 3: " << bureaucrat3.getName() << ", Grade: " << bureaucrat3.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
	// Test impostare un grade troppo basso
		Bureaucrat bureaucrat4("Dave", 151); // Questo lancerà un'eccezione
		std::cout << "Bureaucrat 4: " << bureaucrat4.getName() << ", Grade: " << bureaucrat4.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
	// Test incrementare un grade troppo alto
		Bureaucrat highBureaucrat("Eve", 1);
		std::cout << "High Bureaucrat: " << highBureaucrat.getName() << ", Grade: " << highBureaucrat.getGrade() << std::endl;

		highBureaucrat.incrementGrade(); // Questo lancerà un'eccezione
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
	// Test decrementare un grade troppo basso
		Bureaucrat lowBureaucrat("Frank", 150);
		std::cout << "Low Bureaucrat: " << lowBureaucrat.getName() << ", Grade: " << lowBureaucrat.getGrade() << std::endl;

		lowBureaucrat.decrementGrade(); // Questo lancerà un'eccezione
	}
		catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
