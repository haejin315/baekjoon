
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    queue<int> a;
    int N, K, b;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        a.push(i);
    }
    cout << "<";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < K; j++) {
            b = a.front();
            a.pop();
            a.push(b);
        }
        cout << a.front();
        if (i != N)cout << ", ";
        a.pop();
    }
    cout << ">";
}

