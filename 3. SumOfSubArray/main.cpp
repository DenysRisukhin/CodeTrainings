#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <iomanip>
#include <exception>

using namespace std;

// O(n)
void find_subarray(const int * _array,
	               int _size,
	               int & _begin,
	               int & _end
 )
{
	int sum = 0;
	int curSum = 0;
	int i = 0;
	int j = 0;

	for ( ; j < _size ; j++)
	{
		if (_array[j] < 0) {

			if (curSum < sum)
			{
				_begin = i;

				_end = j - 1;

				curSum = sum;
			}

			sum += _array[j];

			if (sum <= 0)
			{
				i = j + 1;

				sum = 0;
			}
		}
		else
			sum += _array[j];
	}

	if (curSum < sum)
	{
		_begin = i;

		_end = j - 1;
	}

}
int main() {
		
	const int size = 15;

	int arr[size] = { 1110, 2 , 6 ,-9, 5 , 116, -8000, 9, -66, 443, -3, 1, -6, 90005, 7 };

	int begin = 0;
	int end = 0;

	find_subarray(arr, size, begin, end);

	cout << begin << ' ' << end << endl;
	cout << endl;

	system("pause");

	return 0;
}

