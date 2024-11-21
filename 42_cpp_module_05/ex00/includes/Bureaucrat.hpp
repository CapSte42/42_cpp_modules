#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <string>
//# include <stdexcept>

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

std::ostream &operator<<(std::ostream &os, Bureaucrat const &beureucrat);

#endif // Bureaucrat_HPP
