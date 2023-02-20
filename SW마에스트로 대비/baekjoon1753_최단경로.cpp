#include <iostream>
#include <queue>
#include <deque>

using namespace std;

deque<pair<int, int>> e[20001];
deque<int> f(20001, 4000000);

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int V, E, K, in1, in2, in3;
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        cin >> in1 >> in2 >> in3;
        e[in1].push_back(pair<int, int>(in2, in3));
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> a;
    a.push(pair<int, int>(0, K));

    while (!a.empty()) {
        int af = a.top().first;
        int as = a.top().second;
        a.pop();

        for (int i = 0; i < e[as].size(); i++) {
            int k1 = e[as][i].first;
            int k2 = af + e[as][i].second;

            if (k2 < f[k1]) {
                f[k1] = k2;
                a.push({ k2, k1 });
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (i == K)cout << "0\n";
        else if (f[i] == 4000000) {
            cout << "INF\n";
        }
        else cout << f[i] << "\n";
    }
}

