#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;


class Bureaucrat
{
	private:

		std::string const _name;
		int _grade;

	public:

		Bureaucrat();
		Bureaucrat(std::string const name);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string const getName() const;
		int getGrade() const;
		void setGrade(int grade);

		void incrementGrade();
		void decrementGrade();

		void outOfRange(int grade) const;

		void signForm(AForm &AForm);
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();

		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif // Bureaucrat_HPP
