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
	
int main() {
		
	cout << is_unique_chars("asdafg");

	cout << endl;

	system("pause");

	return 0;
}

