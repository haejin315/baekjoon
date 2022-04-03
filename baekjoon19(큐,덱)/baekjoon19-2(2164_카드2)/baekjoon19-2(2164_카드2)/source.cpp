
#include <iostream>
#include <queue>    

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, a;
    cin >> N;
    queue<int> b;
    for (int i = 1; i <= N; i++) {
        b.push(i);
    }
    while (b.size() > 1) {
        b.pop();
        a = b.front();
        b.pop();
        b.push(a);
    }
    cout << b.front();
}

