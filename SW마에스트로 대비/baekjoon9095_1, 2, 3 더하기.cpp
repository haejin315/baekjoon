#include <iostream>

using namespace std;


int main()
{
	int a = 0, c;
	int b[12] = { 0 };
	cin >> a;
	b[1] = 1;
	b[2] = 2;
	b[3] = 4;
	for (int i = 0; i < a; i++) {
		cin >> c;
		for (int j = 4; j <= c; j++) {
			if (b[j] == 0)b[j] = b[j - 1] + b[j - 2] + b[j - 3];
		}
		cout << b[c] << "\n";
	}
}

