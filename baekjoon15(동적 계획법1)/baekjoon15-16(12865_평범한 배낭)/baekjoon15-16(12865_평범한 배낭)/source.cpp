
#include <iostream>
#include <algorithm>

using namespace std;

int a[101][2] = { 0 };
int b[101][100001] = { 0 };

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= a[i][0])
				b[i][j] = max(b[i - 1][j], (b[i - 1][j - a[i][0]]) + a[i][1]);
			else
				b[i][j] = b[i - 1][j];
		}
	}
	cout << b[N][K];
}

