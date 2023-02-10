#include <iostream>

using namespace std;


int main()
{
	int n, a[501][501] = {0}, b;
	cin >> n >> a[0][0];
	for (int i = 1; i < n; i++) {
		cin >> b;
		a[i][0] = a[i - 1][0] + b;
		for (int j = 1; j <= i; j++) {
			cin >> b;
			a[i][j] = a[i - 1][j - 1] > a[i - 1][j] ? a[i - 1][j - 1] + b : a[i - 1][j] + b;;
		}
	}
	for (int i = 0; i < n; i++) {
		b = a[n - 1][i] > b ? a[n - 1][i] : b;
	}
	cout << b;
}

