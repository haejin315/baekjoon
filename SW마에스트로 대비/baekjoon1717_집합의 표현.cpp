#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int parent[1000001];

int find(int x) {
	if (parent[x] == x) // 배열 인덱스와 값이 같다면 해당 값 리턴
		return x;
	return parent[x] = find(parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
}

void merge(int x, int y) {
	x = find(x);
	y = find(y); // 각각 find연산을 통해 루트 노드를 가짐
	if (x == y) return; // x와 y가 같다면 이미 연결되어있는 것
	parent[y] = x; // 배열의 y인덱스에 x값을 저장
}

string isUnion(int x, int y) { // 두 노드가 연결되어있는지 판별하는 함수
	x = find(x);
	y = find(y);
	if (x == y)
		return "YES";
	return "NO";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { // 배열 초기화 과정
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0) {
			merge(b, c);
		}
		else {
			cout << isUnion(b, c) << "\n";
		}
	}
}

