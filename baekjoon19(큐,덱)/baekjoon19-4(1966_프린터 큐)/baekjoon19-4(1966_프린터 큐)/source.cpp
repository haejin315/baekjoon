
#include <iostream>
#include <deque>

using namespace std;

bool check(deque<int> a1) {
    for (int i = 1; i < a1.size(); i++) {
        if (a1[0] < a1[i])return 0;
    }
    return 1;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M, c, ans, a;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ans = 0;
        deque<int> b;
        cin >> M >> c;
        for (int j = 0; j < M; j++) {
            cin >> a;
            b.push_back(a);
        }
        while (1) {
            if (c == 0 && check(b) == 1) {
                cout << ans + 1<< "\n";
                break;
            }
            if (check(b) == 0) {
                b.push_back(b[0]);
                b.pop_front();
            }
            else if (check(b) == 1) {
                b.pop_front();
                ans++;
            }
            if (c == 0)c = b.size() - 1;
            else c--;
        }
        
    }
}

