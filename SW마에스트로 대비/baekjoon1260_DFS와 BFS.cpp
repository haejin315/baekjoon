#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> a[1001];
deque<int> a2;
int d[1001][2] = { 0 };

void dfs(int start) {
	d[start][0] = 1;
	cout << start << " ";
	sort(a[start].begin(), a[start].end());
	for (int i = 0; i < a[start].size(); i++) {
		if (a[a[start][i]].size() != 0 && d[a[start][i]][0] != 1) {
			dfs(a[start][i]);
		}
	}
}

void bfs(int start) {
	a2.push_back(start);
	d[start][1] = 1;
	while (!a2.empty()) {
		sort(a[a2.front()].begin(), a[a2.front()].end());
		for (int i = 0; i < a[a2.front()].size(); i++) {
			if (d[a[a2.front()][i]][1] == 1)continue;
			else {
				a2.push_back(a[a2.front()][i]);
				d[a[a2.front()][i]][1] = 1;
			}
		}
		cout << a2[0] << " ";
		a2.pop_front();
	}
}

int main()
{

	int n, m, v, b, c;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> b >> c;
		a[b].push_back(c);
		a[c].push_back(b);
	}
	dfs(v);
	cout << "\n";
	bfs(v);
}

