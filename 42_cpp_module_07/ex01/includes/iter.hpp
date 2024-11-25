#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T *array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void print(T const &x)
{
	std::cout << "< " << x << " >";
}

//esempio con overload per tipo string
void print(std::string const &x);

#endif