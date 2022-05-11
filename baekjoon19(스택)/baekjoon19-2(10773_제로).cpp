
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    stack<int> a;
    int N, b, c;
    c = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b == 0 && a.size() != 0) {
            c -= a.top();
            a.pop();
        }
        else if (b != 0) {
            a.push(b);
            c += b;
        }
    }
    cout << c;
}

