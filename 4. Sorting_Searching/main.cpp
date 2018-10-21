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

// quickSort     O(nlog(n)) квазилинейная
// boubleSort    O(n^2)     полиномиальная
// mergeSort     O(nlog(n)) квазилинейная
// binarySearch  O(log(n))  логарифмическая
// рекурсия      O(m^n)     экспоненциальная
	

// O(nlog(n)) - квазилинейная 

void mergeSort(int * _arr, int * _helper, int _low, int _middle, int _hight)
{
	for (int i = _low; i <= _hight; i++)
		_helper[i] = _arr[i];

	int helperLeft = _low;
	int helperRight = _middle + 1;
	int current = _low;

	while (helperLeft <= _middle && helperRight <= _hight)
	{
		if (_helper[helperLeft] <= _helper[helperRight])
		{
			_arr[current] = _helper[helperLeft];

			helperLeft++;
		}
		else
		{
			_arr[current] = _helper[helperRight];

			helperRight++;
		}

		current++;
	}

	int remaning = _middle - helperLeft;

	for (int i = 0; i <= remaning; i++)
		_arr[current + i] = _helper[helperLeft + i];
}

void mergeSort(int * _arr, int * _helper, int _low, int _hight) 
{
	if (_low < _hight)
	{
		int middle = (_low + _hight) / 2;

		cout << "sort left side" << "   _low: " << _low << "   _hight: " << _hight << endl;
		mergeSort(_arr, _helper, _low, middle); // sort left side

		cout << "sort right side" << "  _low: " << _low << "   _hight: " << _hight << endl;

		mergeSort(_arr, _helper, middle + 1, _hight); // sort right side

		cout << "merge" << endl;

		mergeSort(_arr, _helper, _low, middle, _hight); // merge
	}
	else
		cout << endl << "end recursion" << endl << endl;
}

void mergeSort(int * _arr, int _size) 
{
	int * helper = new int[_size];

	mergeSort(_arr, helper, 0, _size - 1);

	if (helper)
	{
		delete[] helper;

		helper = NULL;
	}
}

void swap(int & a, 
	      int & b
 )
{
	int t = a;
	a = b;
	b = t;
}

// O(n^2) полиномиальная
void boubleSort(int * _arr,
	            int _size
 )
{
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size - i; j++)
			if (_arr[j] > _arr[j + 1])
				swap(_arr[j], _arr[j + 1]);
}

int binarySearch(int * _arr,
               	 int _r,
	             int _val
)
{
	int left = 0;
	int right = _r;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (_arr[middle] == _val) 
			return middle
		else if (_val < _arr[middle])
			right = middle - 1;
		else if (_arr[middle] < _val)
			left = middle + 1;
	}

	return -1;
}

int processing(int * _array,
	int _l,
	int _h
 )
{
	int pivot = _array[(_l + _h) / 2];

	while (_l <= _h)
	{
		while (_array[_l] < pivot)
			_l++;

		while (pivot < _array[_h])
			_h--;

		if (_l <= _h)
		{
			swap(_array[_l], _array[_h]);
			_l++;
			_h--;
		}
	}

	return _l;
}

void quickSort(int * _array,
	           int _l, 
	           int _h
 )
{
	int index = processing(_array, _l, _h);

	if (_l < index - 1)
		quickSort(_array, _l, index - 1);
	
	if (index < _h )
		quickSort(_array, index, _h);

}


}

int main() {
		
	const int size = 15;

	int arr[size] = { 1110, 2 , 6 ,-9, 5 , 116, -8000, 9, -66, 443, -3, 1, -6, 90005, 7 };

	quickSort(arr, 0, size - 1);
	//boubleSort
	//mergeSort
	//binarySearch

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	
	cout << endl;

	system("pause");

	return 0;
}

