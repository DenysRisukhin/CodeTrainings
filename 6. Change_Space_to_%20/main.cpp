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
	
int main() {
		
	cout << replace_spaces("a sd f");

	cout << endl;

	system("pause");

	return 0;
}

