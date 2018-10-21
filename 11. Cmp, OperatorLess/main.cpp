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


char * replace_spaces(const char *_str)
{
	const char * cpy = _str;

	int spaceCounter = 0;

	while (*_str++)
		if (*_str == ' ')
			spaceCounter++;

	_str = cpy;

	int size =  (sizeof(_str) / sizeof(char) + spaceCounter * 3);

	char *newStr = new char[size];

	while (*_str)
	{
		if (*_str == ' ')
		{
			*newStr++ = '%';
			*newStr++ = '2';
			*newStr = '0';
		}
		else
		{
			*newStr = *_str;
		}

		*newStr++;
		*_str++;
	}

	*newStr = '\0';

	newStr -= size;

	return newStr;
}

void mergeArr(int * _arrA, 
	int _lowA, 
	int _highA, 
	int * _arrB,
	int _lowB, 
	int _highB, 
	int * _arrRes,
	int _lowRes
 )
{
	int ndxA = _lowA;
	int ndxB = _lowB;
	int ndxRes = _lowRes;

	while (ndxA < _highA)
		_arrRes[ndxRes++] = _arrA[ndxA++];
	
	while (ndxB < _highB) 
		_arrRes[ndxRes++] = _arrB[ndxB++];
}

bool is_unique_chars(char * _str)
{
	char *cpy = _str;
	for (; *_str; *_str++)
	{
		for (char sign = *_str++; *_str; *_str++)
		{
			if (sign == *_str)
				return false;
		}

		_str = ++cpy;
	}

	return true;
}

bool is_unique_chars(string _str) 
{
	bool signSet[256] = { false };

	for (int i = 0; i < _str.size(); i++)
	{
		int val = _str[i];

		if (signSet[val])
			return false;

		signSet[val] = true;
	}

	return true;
}

void matrixNull(int (* _matrix) [4], int _size)
{
	vector<int> r;
	vector<int> c;

	for (int i = 0 ; i < _size ; i++)
		for (int j = 0; j < _size; j++)
			if (_matrix[i][j] == 0) {
				r.push_back(i);
				c.push_back(j);
			}

	if (!r.empty())
		for (int i : r)
			for (int j = 0; j < _size; j++)
				_matrix[i][j] = 0;

	if (!c.empty())
		for (int j : c)
			for (int i = 0; i < _size; i++)
				_matrix[i][j] = 0;
}

int rotate(int ** _matrix, 
	        const int _n
 )
{
	int cicleCount = 0;

	for (int layer = 0; layer < _n / 2; layer++)
	{
		int first = layer;

		int last = _n - 1 - layer;

		for (int i = first; i < last; i++)
		{
			int offset = i - first;

			// save top
			int top = _matrix[first][i];

			// left -> top
			_matrix[first][i] = _matrix[last - offset][first];

			// bottom -> left
			_matrix[last - offset][first] = _matrix[last][last - offset];

			// right -> bottom
			_matrix[last][last - offset] = _matrix[i][last];

			// top -> right
			_matrix[i][last] = top;

		}
	}

	return cicleCount;
}

// компаратор писать ненужно если для данного типа перегружен operator<.
// компаратор можно передавать по &

struct Team {
	string name;
	int task;
	int penalty;
};

bool cmp(Team a, 
	     Team b
 )
{
	return a.penalty < b.penalty;
}

// можно сортировать по убыванию последних цифр в числах.
// Если число одинаковое сравниваем по 1-ым числам

bool cmp(Team a, 
	     Team b
 )
{
	if (a.task % 10 != b.task % 10)
		return a.task % 10 > b.task % 10;
}

// *******

// Для Data компаратор не нужен т к есть operator<
struct Data {
	int a, b, c;
};

Data Q[100];

bool operator<(const Data & _p,
	           const Data & _t
 )
{
	if (_p.c % 10 != _t.c %10)
		return _p.c % 10 < _t.c % 10;

	return _p.a < _t.b;
}

int main() {
	
	vector<Team> teams;

	sort( teams.begin(), teams.end(), cmp);
	
	cout << endl;

	system("pause");

	return 0;
}

