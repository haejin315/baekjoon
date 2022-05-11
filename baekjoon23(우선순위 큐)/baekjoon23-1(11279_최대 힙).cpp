
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int> a;
    int N, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b == 0) {
            if (a.size() == 0)cout << "0\n";
            else {
                cout << a.top() << "\n";
                a.pop();
            }
        }
        else a.push(b);
    }
}

