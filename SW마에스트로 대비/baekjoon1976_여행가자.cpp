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

int parent[201];

int ufind(int x) {
    if (x == parent[x])return x;
    return parent[x] = ufind(parent[x]);
}

void umerge(int x, int y) {
    x = ufind(x);
    y = ufind(y);
    if (x == y)return;
    parent[y] = x;
}

bool isUnion(int x, int y) {
    x = ufind(x);
    y = ufind(y);
    if (x == y)return 1;
    return 0;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, a, b[1001];
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> b[j];
        }
        for (int j = 1; j < N; j++) {
            if (b[j] == 1) {
                umerge(i, j);
            }
        }
    }
	
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < M; i++) {
        if (!isUnion(b[i], b[i + 1])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}

