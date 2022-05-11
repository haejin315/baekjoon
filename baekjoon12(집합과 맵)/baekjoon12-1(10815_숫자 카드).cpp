
#include <iostream>
#include <map>

using namespace std;

map<int, int> a;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.insert({ b, b });
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b;
        if (a.find(b) == a.end())cout << "0 ";
        else cout << "1 ";
    }
}

