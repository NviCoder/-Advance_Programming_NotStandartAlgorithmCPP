#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>
using std::cout; using std::endl;

template <typename T>
const T Median(const T& b_it, const T& e_it, unsigned int n)
{
	unsigned int length = std::distance(b_it,e_it);
	T inserter_it = e_it;

	if (length % n != 0 || length == 0)
		return inserter_it;
	
	std::sort(b_it, e_it);

	if (n == 1)
		return inserter_it;

	T m_it = b_it;
	int m_it_position = 0;
	bool first_iteration = true;
	inserter_it = b_it;

	while (m_it_position + n <= length)
	{
		if (first_iteration)
		{
			m_it = b_it + (n / 2);
			m_it_position += (n / 2);
			first_iteration = false;
		}
		else
		{
			m_it += n;
			m_it_position += n;
		}

		if ((n % 2) != 0) //n is odd & bigger then 1 - median is the middle value
			*inserter_it = *m_it;
		else //n is even - median is the avg of the 2 middle values
			*inserter_it = (*m_it + *(m_it - 1)) / 2;

		inserter_it++;
	}

	return inserter_it;
};

template <typename T>
const T Transpose(const T& b_it, const T& e_it)
{
	int length = std::distance(b_it,e_it);
	T it = b_it;
	for (int i = 0; i < length-1; i += 2)
		std::iter_swap(it + i, it + (i + 1));
	if (length % 2 == 0)
		return e_it;
	else
		return (e_it - 1);
};

template <typename T, typename F>
const T Transformations(const T& b_it, const T& e_it, F&& f)
{
	int length = std::distance(b_it, e_it);
	if (length % 2 != 0 || length == 0)
		return e_it;
	else
	{
		T insertion_it = b_it;

		int n = length / 2;
		for (int i = 0; i < n; i++)
		{
			*(insertion_it) = f(b_it[2 * i], b_it[(2 * i) + 1]);
			insertion_it++;;
		}

		return insertion_it;
	}
};