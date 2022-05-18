
#include <iostream>
#include <map>

using namespace std;

map<int, int> a;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, b, ans = 0;;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.insert({ b, 1 });
    }
    for (int i = 0; i < M; i++) {
        cin >> b;
        if (a[b] == 1)ans++;
    }
    cout << N + M - 2 * ans;
}

