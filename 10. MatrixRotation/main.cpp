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
	
int main() {
		
	 int** matrix = new int*[4];

	 for (int i = 0; i<4; i++)
		 matrix[i] = new int[4];
	 

	 for (int i = 0; i<4; i++)
	 {
		 for (int j = 0; j<4; j++)
		 {
			 matrix[i][j] = rand() % 10;
		 }
	 }


	 for (int i = 0; i < 4; i++)
	 {
		 cout << endl;
		 for (int j = 0; j < 4; j++)
			 cout << matrix[i][j] << ' ';
	 }

	rotate(matrix, 4);

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

