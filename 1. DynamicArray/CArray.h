#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename TData>
class CArray 
{
public: // Interface

	// C-tor by default
	CArray();
		
	// C-tor
	CArray(
		int _size = 0,
		int _maxSize = 0,
		TData * _array = NULL
	 );

	// Copy c-tor
	CArray(
		const CArray<TData> & _array
	 );

	//  Destructor
	~CArray();

	void push_back(
		const TData & _value
	 );

	// Add an element to the end of the array
	void insert(
		unsigned int _index,
		const TData & _value
	 );

	// Add array element at specified index
	void erase(
		unsigned int _index
	 );

	// Ñlear array
	void clear();

	// Get array size
	unsigned int size() const;

	// Get array element at specified index
	TData & operator[](
		unsigned int _index
	 ); 

	// Overload of operator =
	CArray<TData> & operator = (
		const CArray<TData> & _array
	 );
	
	// Overload of operator <<
	friend ostream & operator << (
		ostream & _output,
		const CArray<TData> & _array
	 );

	// Overload of operator ==
	friend bool operator == (
		const CArray<TData>& _lhs,
		const CArray<TData>& _rhs
	 );

	// Serch an element in the array
	int search(
		const TData & _value
	);

	// Increase or decrease the size of the array by a cpecified number of elements
	void resize(
		int _delta
	 );
	
	// Print array on the screen
	void print() const;

	// Array sorting
	void sort();

	// Elements are swapped in an array
	void swap(
		TData & _left,
		TData & _right
	);

protected: // Attributes

	// Number of elements in an array
	int curSize;

	// Maximum number of elements in an array
	int maxSize;

	TData * array;

private:

	// shrink array size
	void shrink(
		int _delta
	 );

	// Increase array size
	void enlarge(
		int _delta
	 );

	// Array sorting
	void quickSort(
		TData * _array, 
		int _left, int _right
	 );	
};

template<typename TData>
CArray<TData>::CArray()
{
	curSize = maxSize = 0;

	array = NULL;
}

template<typename TData>
CArray<TData>::CArray(
	int _size, 
	int _maxSize, 
	TData * _array
 )
{
	if ((curSize = _size) < 0)
		throw out_of_range("CArray c-tor: Negative array size");

	maxSize = (_maxSize < _size ? _size : _maxSize);

	array = new TData[maxSize];

	if (_array)
		for (int i = 0; i < curSize; i++)
			array[i] = _array[i];
}

template<typename TData>
CArray<TData>::CArray(
	const CArray<TData> & _array
)
{
	curSize = maxSize = 0;

	*this = _array;
}

template<typename TData>
CArray<TData>::~CArray()
{
	delete [] array;
}

template<typename TData>
void CArray<TData>::push_back(
	const TData & _value
)
{
	resize(1);

	array[curSize - 1] = _value;
}

template<typename TData>
void CArray<TData>::insert(
	unsigned int _index,
	const TData & _value
 )
{
	if (_index < 0 || _index >= curSize)
		throw out_of_range("operator[]: array index is out of range");

	resize(1);
	
	for (int i = curSize - 1 ; i >= _index ; i--) {

		array[i + 1] = array[i];

		if (!i)
			break;
	}
	
	array[_index] = _value;
}

template<typename TData>
int CArray<TData>::search(
	const TData & _value
 )
{
	int low = 0;
	int height = curSize - 1;

	//TData middle;

	while (height >= low)
	{
		TData middle = (low + height) / 2;

		if (array[middle] < _value)
			low = middle + 1;
		else if (array[middle] > _value)
			height = middle - 1;
		else
			return middle;
	}
	
	return -1;

	

	/*int low = 0;
	int high = curSize - 1;

	TData mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (searchValue == array[mid]) {
			return mid;
		}
		else if (searchValue > array[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;*/
}

template<typename TData>
void CArray<TData>::erase(
	unsigned int _index
)
{
	if (_index < 0 || _index >= curSize)
		throw out_of_range("operator[]: array index is out of range");

	for (int i = _index; i < curSize; i++)
		array[i] = array[i + 1];

	resize(-1);
}

template<typename TData>
void CArray<TData>::clear()
{
	curSize = 0;
}

template<typename TData>
unsigned int CArray<TData>::size() const
{
	return curSize;
}

template<typename TData>
TData & CArray<TData>::operator[] (
	unsigned int _index
	)
{
	if (_index < 0 || _index >= curSize)
		throw out_of_range("operator[]: array index is out of range");

	return array[_index];
}

template<typename TData>
CArray<TData> & CArray<TData>::operator = (
	const CArray<TData> & _obj
 )
{
	resize(_obj.curSize - curSize);

	for (int i = 0; i < curSize; i++)
		array[i] = obj.array[i];

	return *this;
}

template<typename TData>
ostream & operator << (
	ostream & _output,
	const CArray<TData> & _array
 )
{
	for (int i = 0; i < curSize; i++)
		_output << _array[i] << ' ';

	return _output;
}

template<typename TData>
bool operator == (
	const CArray<TData>& _lhs,
	const CArray<TData>& _rhs
	)
{
	for (int i = 0; i < curSize; i++)
	{
		if (_lhs[i] == _rhs[i])
		{
			return false;
		}
	}

	return true;
}

template<typename TData>
void CArray<TData>::resize(
	int _delta
 )
{
	if (_delta > 0)
		enlarge(_delta);
	else if (_delta < 0)
		shrink(-_delta);
}

template<typename TData>
void CArray<TData>::shrink(
	int _delta
 )
{
	curSize = (_delta > curSize ? 0 : curSize - _delta);
}

template<typename TData>
void CArray<TData>::enlarge(
	int _delta
 )
{
	if ((curSize += _delta) > maxSize)
	{
		maxSize = curSize;

		TData * newArr = new TData[maxSize];

		for (int i = 0 ; i < curSize - _delta ; i++)
			newArr[i] = array[i];

		array = newArr;
	}
}

template<typename TData>
void CArray<TData>::print() const
{
	for (int i = 0 ; i < curSize; i++)
		cout << array[i] << ' ';

	cout << endl;
}

template<typename TData>
void CArray<TData>::sort()
{
	quickSort(array, 0, curSize);
}

template<typename TData>
void CArray<TData>::quickSort(
	TData * _array, 
	int _left, 
	int _height
 )
{
	if (_height > _left)
	{
		int partition = rand() % (_height - _left) + _left;

		TData data = _array[partition];

		// divide
		swap(_array[_left], _array[partition]);

		size_t i = _left;

		size_t j = i + 1;

		while (j < _height)
		{
			while (_array[j] > data && j < _height)
				j++;

			if (j < _height)
			{
				i++;

				swap(_array[i], _array[j]);

				j++;
			}
		}

		swap(_array[i], _array[_left]);

		quickSort(_array, _left, i);

		quickSort(_array, i + 1, _height);
	}
}

template<typename TData>
void CArray<TData>::swap(
	TData & _left, 
	TData & _right
 )
{
	TData temp = _left;

	_left = _right;

	_right = temp;
}

