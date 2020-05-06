#pragma once
#include <algorithm>
#include <iterator>
#include <iostream>
using std::cout;
using std::endl;

/*
  This Algorithm swap sum up n elements on this container and puts this in the beginig of the continaer.
  p = Add_n(b,e,n) ---> begain , end , number.
  Returns
  if length/n = 0 -> e
  Else -> 1....n-1
*/
template <typename T>
const T Add_n(const T &b_it, const T &e_it, unsigned int n)
{
	unsigned int length = std::distance(b_it, e_it);
	T inserter_it = b_it;

	if (length % n != 0 || length == 0)
	{
		int sum = std::accumulate(b_it, e_it, 0);
		*(inserter_it) = sum;
	}

	else
	{
		if (n == 1)
			return inserter_it;

		T currunt_it_position = b_it;

		while (currunt_it_position + n <= length)
		{
			T end_n = currunt_it_position + n;
			int sum = std::accumulate(currunt_it_position, end_n, 0);
			*(inserter_it) = sum;
			inserter_it++;
			currunt_it_position = end_n;
		}
	}
	return inserter_it;
};

//----------------------------------------------------------------//

/*
  This Algorithm swap between two Adjacent elements on this container
  P = Transpose(b,e) ---> begain , end
  Returns
  Even - e
  Odd - e - 1
 */
template <typename T>
const T Transpose(const T &b_it, const T &e_it)
{
	int length = std::distance(b_it, e_it);
	T it = b_it;
	for (int i = 0; i < length - 1; i += 2)
		std::iter_swap(it + i, it + (i + 1)); //Swapping the elements
	if (length % 2 == 0)					  // Checks if the length is even or odd!
		return e_it;
	else
		return (e_it - 1);
};

/*
 This Algorithm invoke function "f" on two Adjacent elements on the container and so on.
  p = Transform(b,e,o,f) ---> begain , end , other begain , function.
  Returns
  Even - The place after the last element on the second container
  Odd - o.

*/
template <typename T, typename G, typename F>
const G Transform(const T &b_it, const T &e_it, const G &o_it, F &&f)
{
	int length = std::distance(b_it, e_it);
	if (length % 2 != 0 || length == 0)
		return o_it;
	else
	{
		G insertion_it = o_it;

		int n = length / 2;
		for (int i = 0; i < n; i++)
		{
			*(insertion_it) = f(b_it[2 * i], b_it[(2 * i) + 1]);
			insertion_it++;
			;
		}

		return insertion_it;
	}
};
