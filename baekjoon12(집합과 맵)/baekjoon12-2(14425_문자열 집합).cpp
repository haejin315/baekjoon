
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> a;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, ans = 0;
    string b;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.insert({ b,0 });
    }
    for (int i = 0; i < M; i++) {
        cin >> b;
        if (a.find(b) != a.end())ans++;
    }
    cout << ans;
}

