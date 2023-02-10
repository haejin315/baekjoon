#include <iostream>

using namespace std;

int a[1000001] = { 0 };

int main()
{

	int s;
	cin >> s;
	a[1] = 0;

	for (int i = 2; i <= s; i++) {
		if (i % 3 == 0 && i % 2 == 0)a[i] = (a[i - 1] < a[i / 2] ? a[i - 1] : a[i / 2]) < a[i / 3] ? (a[i - 1] < a[i / 2] ? a[i - 1] : a[i / 2]) + 1 : a[i / 3] + 1;
		else if (i % 3 == 0) a[i] = a[i - 1] < a[i / 3] ? a[i - 1] + 1 : a[i / 3] + 1;
		else if (i % 2 == 0) a[i] = a[i - 1] < a[i / 2] ? a[i - 1] + 1 : a[i / 2] + 1;
		else a[i] = a[i - 1] + 1;
		
	}
	cout << a[s];
}

