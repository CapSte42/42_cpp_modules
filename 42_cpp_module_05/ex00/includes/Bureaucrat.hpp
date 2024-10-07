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

		std::string const &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		bool outOfRange(int grade) const;

		class SetGradeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is not set";
				}
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high";
				}

		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too low";
				}
		};
};

#endif // Bureaucrat_HPP
