#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;
    int N, c, mid;
    cin >> N >> mid;
    cout << mid << "\n";
    for (int i = 1; i < N; i++) {
        cin >> c;
        if (c >= mid) {
            if (a.size() >= b.size()) {
                b.push(c);
            }
            else {
                a.push(mid);
                b.push(c);
                mid = b.top();
                b.pop();
            }
        }
        else {
            if (a.size() < b.size()) {
                a.push(c);
            }
            else {
                b.push(mid);
                a.push(c);
                mid = a.top();
                a.pop();
            }
        }
        cout << mid << "\n";
    }
}

