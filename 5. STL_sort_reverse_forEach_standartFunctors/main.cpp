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

// STL

// sort     
// reverse      
// greater<int>() / less<int>()    
// for_each 
// lymbda      
	
int main() {
		
	int arr[] = { 1110, 2 , 6 ,-9, 5 , 116, -8000, 9, -66, 443, 0, -3, 1, -6, 90005, 7 };

	int size = sizeof(arr) / sizeof(int);

	// ***********
	// **Part 1
	// ***********
	sort(arr, arr + size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	cout << endl;

	sort(arr, arr + size, greater<int>());

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	cout << endl;

	sort(arr, arr + size, less<int>());

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' '; 

	cout << endl;

	// ***********
	// **Part 2
	// ***********
	int neg = 0;

	int pos = 0;

	for_each(arr, arr + size, [&](int val) {
		if (val < 0)
			neg++;
		else if (val > 0)
			pos++;
	});

	reverse(arr, arr + size);

	reverse(arr, arr + pos);

	reverse(arr + size - neg, arr + size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	cout << endl;

	system("pause");

	return 0;
}

