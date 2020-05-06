#include "alg.h"
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;



void old_median_test() {

	cout << "****Median() Test****" << endl;

	cout << "Test #1" << endl;
	vector<int> v1{ 1,2,3,8,6,80 };
	 vector<int>::iterator p = Median(v1.begin(), v1.end(), 8);
	cout << endl;

	cout << "Test #2" << endl;
	vector<int> v2{ 1,2,3,8,6,80 };
	Median(v2.begin(), v2.end(), 1);
	cout << endl;

	cout << "Test #3" << endl;
	vector<int> v3{ 1,2,3,8,6,80 };
	Median(v3.begin(), v3.end(), 6);
	cout << endl;


	cout << "Test #4" << endl;
	vector<int> v4{ 1,2,3,8,6,80 };
	Median(v4.begin(), v4.end(), 3);
	cout << endl;


	cout << "Test #5" << endl;
	vector<int> v5{ 1,2,3,8,6,80 };
	Median(v5.begin(), v5.end(), 2);
	cout << endl;

	cout << "Test #6" << endl;
	vector<int> v6{ 1,2,3,8,6,80 };
	Median(v6.begin(), v6.end(), 5);
	cout << endl;


	cout << "Test #7" << endl;
	vector<int> v7;
	Median(v7.begin(), v7.end(), 1);
	cout << endl;


	cout << "Test #8" << endl;
	vector<int> v8{ 1 };
	Median(v8.begin(), v8.end(), 1);
	cout << endl;

	cout << "Test #9" << endl;
	vector<double> v9{ 1,2,3,8,6,80 };
	Median(v9.begin(), v9.end(), 6);
	cout << "answer should be: 4.5" << endl;
	cout << endl;
}

void median_test() {

	//test #1
			cout << "***Test #1:***" << endl;
			cout << "container: int[]" << endl;
			cout <<"n=3" << endl;

			///container
			int arr1[] = { 1, 2, 3, 8, 10, 6, 200, 100, 100 };
	
			//print container before median
			cout << "input: [" << *std::begin(arr1);
			for (auto it = std::begin(arr1) + 1; it != std::end(arr1); ++it) {
				cout << ", " << *it;
			}
			cout << "]" << endl;

			//call Median()
			auto p = Median(std::begin(arr1), std::end(arr1), 3);

			//print array after median
			cout << "output: [" << *std::begin(arr1);
			for (auto it = std::begin(arr1) + 1; it != std::end(arr1); ++it) {
				cout << ", " << *it;
			}
			cout << "]" << endl;

			cout << "p points at: " << *p << endl << endl;

	//test #2
			cout << "***Test #2:***" << endl;
			cout << "container: vector<int>" << endl;
			cout << "n=3" << endl;

			///container
			vector<int> v1{ 1, 2, 3, 8, 10, 6, 200, 100, 100};

			//print container before median
			cout << "input: [" << *std::begin(v1);
			for (auto it = std::begin(v1) + 1; it != std::end(v1); ++it) {
				cout << ", " << *it;
			}
			cout << "]" << endl;

			//call Median()
			//vector<int>::iterator p = 
			vector<int>::iterator pp = Median(std::begin(v1), std::end(v1), 3);

			//print array after median
			cout << "output: [" << *std::begin(v1);
			for (auto it = std::begin(v1) + 1; it != std::end(v1); ++it) {
				cout << ", " << *it;
			}
			cout << "]" << endl;

			cout << "p points at: " << *pp << endl << endl;

}

void transpose_test() {
	cout << "****transpose() Test****" << endl;
	vector<double> v1{ 1.1, 2.2, 3.3, 10.1, 8.1, 6.1 ,22.2 };
	//print container before function
	cout << "input: [" << *std::begin(v1);
	for (auto it = std::begin(v1) + 1; it != std::end(v1); ++it) {
		cout << ", " << *it;
	}
	cout << "]" << endl;

	vector<double>::iterator p = Transpose(v1.begin(), v1.end());

	//print container after function
	cout << "output: [" << *std::begin(v1);
	for (auto it = std::begin(v1) + 1; it != std::end(v1); ++it) {
		cout << ", " << *it;
	}
	cout << "]" << endl;

	if ( p== v1.end() )
		cout << "iterator points at vector end " << endl;
	else
		cout << "iterator points at: " << *p << endl;
	cout << endl;

}

void transformations_test() {
	cout << "****transformations() Test****" << endl;


	int ia[] = { 1,2,3,10,8,6 };

	cout << "before: " << endl;
	for (int i = 0; i < (sizeof(ia) / sizeof(*ia)); i++)
	{
		cout << ia[i] << endl;
	}

	int* p = Transformations(std::begin(ia), std::end(ia), [](const int x, const int y) {return x + y; });
	
	cout << "after: " << endl;
	for (int i = 0; i < (sizeof(ia) / sizeof(*ia)); i++)
	{
		cout << ia[i] << endl;

	}
	cout << "p position = " << *p << endl;

	cout << endl;

}

int main()
{
	//median_test();
	//old_median_test();
	transpose_test();
	//transformations_test();
 }