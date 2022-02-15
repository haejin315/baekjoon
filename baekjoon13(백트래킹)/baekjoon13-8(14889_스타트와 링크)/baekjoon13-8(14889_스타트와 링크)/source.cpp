#include<iostream>

using namespace std;


bool check[21];
int a[21];
int score[21][21];
int small = 20000;

void z(int b, int n) {
	int m = n / 2;
	if (b == m) {
		int team1[10];
		int team2[10];
		int t1 = 0;
		int t2 = 0;
		bool check2[21] = { 0 };
		int ans = 0;
		for (int i = 0; i < m; i++) {
			check2[a[i]] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				team1[t1] = i;
				t1++;
			}
			else {
				team2[t2] = i;
				t2++;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				ans += score[team1[i]][team1[j]];
				ans += score[team1[j]][team1[i]];
				ans -= score[team2[i]][team2[j]];
				ans -= score[team2[j]][team2[i]];
			}
		}
		if (small > abs(ans))small = abs(ans);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		if (a[b - 1] >= i)continue;
		if (a[0] != 1) {
			return;
		}
		check[i] = true;
		a[b] = i;
		z(b + 1, n);
		check[i] = false;
	}
}
int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> score[j][i];
		}
	}
	a[0] = 1;
	z(0, n);
	cout << small;
}