#include "CArray.h"
#include "Random.h"
#include <iostream>
#include <ctime>

using namespace std;

template<typename TData>
void sort(
    CArray<TData> & _array
 )
{
	for (int i = 0; i < _array.size() - 1 ; i++)
	{
		for (int j = 0; j < _array.size() - i - 1; j++)
		{
			if (  _array[j].length()  > _array[j + 1].length() )
			{
				auto temp = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = temp;
			}
		}
	}
}

template<typename TData>
void removeWords(
	CArray<TData> & _array
 )
{
	for (int i = 0 ; i < _array.size() ; i++)
	{
		if ( (_array[i].find('a') != std::string::npos) || (_array[i].find('b') != std::string::npos) ||
			 (_array[i].find('c') != std::string::npos) || (_array[i].find('d') != std::string::npos) ||
			 (_array[i].find('e') != std::string::npos)
			)
		{
			cout << endl << "index[" << i << "] = " << _array[i] << " -> removed" << endl;

			_array.erase(i--);
		}
	}

	cout << endl;
}

template<typename TData>
void insertNewWords(
	CArray<TData> & _array, 
	string _names[],
	size_t _size
 )
{ 
	bool dublicate = false;

	for (int i = 0 ; i < 3 ;)
	{
		auto newWord = _names[Random::GetNumber(_size)];
		
		dublicate = false;
		
		for (int j = 0 ; j < _array.size() ; j++)
		{
			if (_array[j] == newWord)
			{
				cout << "duplicate found: " << newWord << endl;

				dublicate = true;

				break;
			}
		}

			if (dublicate == false)
			{
				cout << "inserting: " << newWord << endl;

				_array.insert(Random::GetNumber(_array.size()), newWord);

				i++;		
	        }
	}

	cout << endl;
}


int main()
{
	// 1. Work with numbers (int).
	//Random::SetRand();

	CArray<int> numbers(0, 25);

	numbers.print();

	cout << "array size:" << numbers.size() << endl << endl;
 
	cout << "1.1" << endl << endl;

	for (int i = 0; i < 20; i++) 
		numbers.push_back(0 + rand() % 100); // Random::GetNumber(100)

	numbers.print();

	cout << "array size:" << numbers.size() << endl << endl;


	cout << "1.2" << endl << endl;

	numbers.sort();

	numbers.print();

	cout << "searching: " << numbers.search(24) << endl;

	cout << "array size:" << numbers.size() << endl << endl;


	cout << "1.3" << endl << endl;

	bool state = false;

	for (int i = 0 ; i < numbers.size() ; i++)
	{
		if (state == false)
		{
			if (i % 2)
			{
				numbers.erase(i);
				state = true;
			}
		}
		else
		{
			if ( !(i % 2) )
			{
				numbers.erase(i);
				state = false;
			}
		}
	}

	numbers.print();

	cout << "array size:" << numbers.size() << endl << endl;


	cout << "1.4" << endl << endl;

	for (int i = 0 ; i < 10 ; i++)
	{
		int index = Random::GetNumber(numbers.size() - 1);

		int value = Random::GetNumber(100);

		numbers.insert(index, value);
	}

	numbers.print();

	cout << "Array size:" << numbers.size() << endl << endl;
	
	cout << "1.5" << endl << endl;

	numbers.clear();

	cout << "array size:" << numbers.size() << endl << endl;

	// 2. Work with objects (std::string).

	string names[] = { "duck", "cat", "dog", "zebra", "dolphin", "alligator", "bear", "bird", "camel", "fox", "frog", "snake", "spider", "rat", "fish", "monkey", "panda", "wolf", "pig", "cow" };

	size_t namesSize = sizeof(names) / sizeof(names[0]);

	CArray<string> animalNames(0, 20);


	cout << "2.1" << endl << endl;

	for (int i = 0 ; i < 15 ; i++)
		animalNames.push_back(names[0 + rand() % 19]);
		
	animalNames.print();

	cout << "array size:" << animalNames.size() << endl << endl;


	cout << "2.2" << endl << endl;

	sort(animalNames);

	animalNames.print();

	cout << "array size:" << animalNames.size() << endl << endl;


	cout << "2.3" << endl << endl;

	removeWords(animalNames);

	animalNames.print();

	cout << "array size:" << animalNames.size() << endl << endl;


	cout << "2.4" << endl << endl;

	insertNewWords(animalNames, names, namesSize);

	animalNames.print();

	cout << "array size:" << animalNames.size() << endl << endl;

	animalNames.clear();

	return 0;
}

