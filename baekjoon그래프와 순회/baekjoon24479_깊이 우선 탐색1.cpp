#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int curNode[200001] = { 0 };
int c = 1;

vector<int> v[100001];


bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void dfs(int R) {
    if (curNode[R] != 0)return;
    curNode[R] = c;
    c++;
    for (int i = 0; i < v[R].size(); i++) {
        dfs(v[R][i]);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, R;
    int a, b;
    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (v[i + 1].size() == 0)continue;
        sort(v[i + 1].begin(), v[i + 1].end());
    }
    dfs(R);
    for (int i = 0; i < N; i++) {
        cout << curNode[i + 1] << "\n";
    }
}

