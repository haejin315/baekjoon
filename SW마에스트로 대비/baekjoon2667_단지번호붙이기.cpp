#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int a[27][27][2] = {0};
int d;
deque<pair<int, int>> b;
deque<int> c;

int main()
{
	int n;
	string e;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> e;
		for (int j = 1; j <= n; j++) {
			a[i][j][0] = e[j - 1] - 48;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j][0] == 0 || a[i][j][1] == 1)continue;
			d = 1;
			a[i][j][1] = 1;
			b.push_back(pair<int, int>(i, j));
			while (!b.empty()) {
				if (a[b.front().first - 1][b.front().second][0] == 1 && a[b.front().first - 1][b.front().second][1] == 0) {
					b.push_back(pair<int, int>(b.front().first - 1, b.front().second));
					a[b.front().first - 1][b.front().second][1] = 1;
					d++;
				}
				if (a[b.front().first][b.front().second - 1][0] == 1 && a[b.front().first][b.front().second - 1][1] == 0) {
					b.push_back(pair<int, int>(b.front().first, b.front().second - 1));
					a[b.front().first][b.front().second - 1][1] = 1;
					d++;
				}
				if (a[b.front().first + 1][b.front().second][0] == 1 && a[b.front().first + 1][b.front().second][1] == 0) {
					b.push_back(pair<int, int>(b.front().first + 1, b.front().second));
					a[b.front().first + 1][b.front().second][1] = 1;
					d++;
				}
				if (a[b.front().first][b.front().second + 1][0] == 1 && a[b.front().first][b.front().second + 1][1] == 0) {
					b.push_back(pair<int, int>(b.front().first, b.front().second + 1));
					a[b.front().first][b.front().second + 1][1] = 1;
					d++;
				}
				b.pop_front();
			}
			c.push_back(d);
		}
	}
	sort(c.begin(), c.end());
	cout << c.size() << "\n";
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << "\n";
	}
}

