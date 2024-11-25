#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T*				_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& src);
		~Array();

		Array<T>& operator=(const Array<T>& src);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# include "Array.tpp"

#endif
