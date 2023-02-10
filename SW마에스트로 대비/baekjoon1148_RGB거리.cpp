#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	int a[1001][3] = { 0 };
	cin >> a[1][0] >> a[1][1] >> a[1][2];
	for (int i = 2; i <= n; i++) {
		cin >> a[0][0] >> a[0][1] >> a[0][2];
		a[i][0] = a[i - 1][1] < a[i - 1][2] ? a[0][0] + a[i - 1][1] : a[0][0] + a[i - 1][2];
		a[i][1] = a[i - 1][0] < a[i - 1][2] ? a[0][1] + a[i - 1][0] : a[0][1] + a[i - 1][2];
		a[i][2] = a[i - 1][1] < a[i - 1][0] ? a[0][2] + a[i - 1][1] : a[0][2] + a[i - 1][0];
	}
	if (a[n][0] > a[n][1])a[n][0] = a[n][1];
	if (a[n][0] > a[n][2])a[n][0] = a[n][2];
	cout << a[n][0];
}

