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

void matrixNull(int (* _matrix) [4], 
                int _size
 )
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
	
int main() {
		
	int matrix[4][4] = {5, 6, 9, 0,
						1, 5, 7, 5,
						3, 0, 5, 4,
						5, 8, 9, 5};

	matrixNull(matrix, 4);

	cout << endl;
	
	for (int i = 0; i < 4; i++)
	{
		cout << endl;
		for (int j = 0; j < 4; j++)
			cout << matrix[i][j] << ' ';
	}

	cout << endl;

	system("pause");

	return 0;
}

