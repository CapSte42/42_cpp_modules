#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>

class Bureaucrat;

class AForm
{
	private:

		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:

		AForm();
		AForm(std::string const name);
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		~AForm();

		std::string const getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void setSigned(bool isSigned);

		void beSigned(Bureaucrat &bureaucrat);

		bool isOutOfRange(int grade) const;

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

#endif // AForm_HPP
