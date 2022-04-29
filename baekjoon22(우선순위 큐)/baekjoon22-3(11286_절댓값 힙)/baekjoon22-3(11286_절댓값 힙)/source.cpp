#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct greater2 {

    const bool operator()(const int _Left, const int _Right) const {
        if (abs(_Left) == abs(_Right)) {
            return _Left > _Right;
        }
        return abs(_Left) > abs(_Right);
    }
};


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater2> a;
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

