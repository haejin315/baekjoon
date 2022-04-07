
#include <iostream>
#include <deque>

using namespace std;

int lo(deque<int> c, int d) {
    for(int i = 0; i < c.size(); i++){
        if (c[i] == d)return i;
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M, a, e, f;
    cin >> N >> M;
    deque<int> b;
    f = 0;
    for (int i = 1; i <= N; i++) {
        b.push_back(i);
    }
    for (int i = 0; i < M; i++) {
        cin >> a;
        e = lo(b, a);
        if (e <= b.size() / 2) {
            for (int j = 0; j < e; j++) {
                b.push_back(b.front());
                b.pop_front();
            }
            f += e;
        }
        else {
            for (int j = 0; j < b.size() - e; j++) {
                b.push_front(b.back());
                b.pop_back();
            }
            f += b.size() - e;
        }
        b.pop_front();
    }
    cout << f;
}

