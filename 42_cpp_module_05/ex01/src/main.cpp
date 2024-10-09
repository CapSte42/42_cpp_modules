#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main()
{
	try
	{
	// Creazione di alcuni oggetti Bureaucrat per i test
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 150);
		Bureaucrat charlie("Charlie", 1);

	// Creazione di un Form valido
		Form form1("Form1", 100, 50);
		std::cout << "Created " << form1.getName() << " with grade to sign: " << form1.getGradeToSign()
			<< " and grade to execute: " << form1.getGradeToExecute() << std::endl;

	// Prova a far firmare il modulo a un Bureaucrat con grade troppo basso
		bob.signForm(form1); // Dovrebbe fallire, bob ha grade 150 > 100 (gradeToSign)
		std::cout << "Current signed status of " << form1.getName() << ": " << (form1.getSigned() ? "Signed" : "Not Signed") << std::endl;

	// Prova a far firmare il modulo a un Bureaucrat con un grade sufficiente
		alice.signForm(form1); // Dovrebbe andare a buon fine, alice ha grade 50 <= 100 (gradeToSign)
		std::cout << "Current signed status of " << form1.getName() << ": " << (form1.getSigned() ? "Signed" : "Not Signed") << std::endl;

	// Creazione di un altro modulo con parametri estremi
		Form form2("Form2", 1, 1); // Richiede il massimo grado per la firma e l'esecuzione
		std::cout << "Created " << form2.getName() << " with grade to sign: " << form2.getGradeToSign()
			<< " and grade to execute: " << form2.getGradeToExecute() << std::endl;

	// Prova a far firmare form2 a Charlie (grade 1)
		charlie.signForm(form2); // Dovrebbe andare a buon fine
		std::cout << "Current signed status of " << form2.getName() << ": " << (form2.getSigned() ? "Signed" : "Not Signed") << std::endl;

	// Tentativo di creare un modulo con grade troppo alto (minore di 1)
		std::cout << "\nAttempting to create a form with too high a grade..." << std::endl;
		Form invalidForm("InvalidForm", 0, 10); // Dovrebbe lanciare un'eccezione
    }
    catch (const std::exception &e)
    {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
	// Tentativo di creare un modulo con grade troppo basso (maggiore di 150)
		std::cout << "\nAttempting to create a form with too low a grade..." << std::endl;
		Form invalidForm2("InvalidForm2", 10, 151); // Dovrebbe lanciare un'eccezione
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}