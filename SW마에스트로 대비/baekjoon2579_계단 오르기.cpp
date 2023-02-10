#include <iostream>

using namespace std;


int main()
{
	int a[300][3] = {0}, b = 0;
	int c;
	cin >> c;
	if (c == 1) {
		cout << a[0][0];
	}
	else if (c == 2) {
		cin >> a[0][0] >> a[1][0];
		cout << a[0][0] + a[1][0];
	}
	else {
		cin >> a[0][0] >> a[1][0] >> a[2][0];
		a[0][1] = a[0][0];
		a[1][1] = a[0][0] + a[1][0];
		if (a[0][0] > a[1][0]) a[2][1] = a[0][1] + a[2][0];
		else {
			a[2][1] = a[1][0] + a[2][0];
			a[2][2] = 1;
		}
		for (int i = 3; i < c; i++) {
			cin >> a[i][0];
			if (a[i - 1][2] == 1) {
				if (a[i - 3][1] + a[i - 1][0] > a[i - 2][1]) {
					a[i][1] = a[i - 3][1] + a[i - 1][0] + a[i][0];
					a[i][2] = 1;
				}
				else {
					a[i][1] = a[i - 2][1] + a[i][0];
				}
			}
			else {
				if (a[i - 1][1] > a[i - 2][1]) {
					a[i][1] = a[i - 1][1] + a[i][0];
					a[i][2] = 1;
				}
				else {
					a[i][1] = a[i - 2][1] + a[i][0];
				}
			}
		}
		cout << a[c - 1][1];
	}
}

