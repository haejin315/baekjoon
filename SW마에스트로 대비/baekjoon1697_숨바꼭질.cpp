#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N, K, s = 0, c = 1, b;
    int d[100001] = { 0 };
    cin >> N >> K;
    if (N > K) {
        cout << N - K;
        return 0;
    }
    deque<int> a;
    a.push_back(N);
    d[N] = 1;
    while (a.front() != K) {
        b = a.front();
        if (b - 1 >= 0 && d[b - 1] != 1) {
            a.push_back(b - 1);
            d[b - 1] = 1;
        }
        if (b + 1 <= 100000 && d[b + 1] != 1) {
            a.push_back(b + 1);
            d[b + 1] = 1;
        }
        if (b * 2 <= 100000 && d[b * 2] != 1) {
            a.push_back(b * 2);
            d[b * 2] = 1;
        }
        a.pop_front();
        c--;
        if (c == 0) {
            s++;
            c = a.size();
        }
    }
    cout << s;
}

