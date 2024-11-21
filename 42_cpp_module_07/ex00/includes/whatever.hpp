#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T1, typename T2>
void swap(T1 &a, T2 &b)
{
	T1 tmp = a;
	a = b;
	b = tmp;
}

template <typename T1, typename T2>
T1 min(T1 a, T2 b)
{
	return (a < b ? a : b);
}

template <typename T1, typename T2>
T1 max(T1 a, T2 b)
{
	return (a > b ? a : b);
}

#endif
