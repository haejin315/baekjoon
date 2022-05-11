
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> n;
int m[100010];
int ans = 0;

void ss(int begin, int end, int target) {
    if (end - begin == 0) {
        if (n[end] != target)return;
    }
    if (end - begin == 1) {
        if (n[end] != target && n[begin] != target)return;
        ans = 1; return;
    }
    if (n[(begin + end) / 2] == target) {
        ans = 1;
        return;
    }
    if (end == begin)return;
    if (n[(begin + end) / 2] > target) {
        ss(begin, (begin + end) / 2 - 1, target);;
    }
    else {
        ss((begin + end) / 2 + 1, end, target);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        n.push_back(a);
    }
    sort(n.begin(), n.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> m[i];
        ss(0, N - 1, m[i]);
        cout << ans << "\n";
        ans = 0;
    }

}

