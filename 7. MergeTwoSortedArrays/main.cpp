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
	
int main() {
		
	int a[5] = {2, 6, 9, 15, 53};

	int b[3] = { 54, 70 , 88};

	int result[8];

	mergeArr(a, 0, 5, b, 0, 3, result, 0);

	for (int i = 0; i < 8; i++)
		cout << result[i] << ' ';

	cout << endl;

	system("pause");

	return 0;
}

