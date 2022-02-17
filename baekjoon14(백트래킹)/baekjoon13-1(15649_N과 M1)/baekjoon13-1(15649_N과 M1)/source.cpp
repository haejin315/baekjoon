#include<iostream>

using namespace std;


bool check[10];
int a[10];
void z(int b, int n, int m) {
	if (b == m) {

		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		a[b] = i;
		z(b + 1, n, m);
		check[i] = false;
	}
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	z(0, n, m);
}