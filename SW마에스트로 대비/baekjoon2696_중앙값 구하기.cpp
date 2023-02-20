#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T, M, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> b;

        deque<int> a;
        a.push_back(b);
        cout << M / 2 + 1 << "\n" << b << " ";
        for (int j = 1; j < M; j++) {
            cin >> b;

            int front = 0, back = a.size() - 1;

            while (1) {
                if (front > back) {
                    a.insert(a.begin() + front, b);
                    break;
                }
                if (a[(front + back) / 2] <= b) {
                    front = (front + back) / 2 + 1;
                }
                else {
                    back = (front + back) / 2 - 1;
                }
            }
            if (a.size() % 2 == 1)cout << a[a.size() / 2] << " ";
        }
        cout << "\n";
    }
}

