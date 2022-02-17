#include <iostream>

using namespace std;

bool lup[27] = { 0 };
bool ldo[27] = { 0 };
bool check[15];
int a[15];
int s = 0;

void z(int b, int n) {
	if (b == n) {

		s++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		if (!lup[i + b] && !ldo[i - b + n - 1]) {
			lup[i + b] = true;
			ldo[i - b + n - 1] = true;
		}
		else {
			continue;
		}
		check[i] = true;
		a[b] = i;
		z(b + 1, n);
		check[i] = false;
		lup[i + b] = false;
		ldo[i - b + n - 1] = false;
	}
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n;
	z(0, n);
	cout << s;
}