#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T, N, M, K, a, b, s;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K;
        int c[52][52] = { 0 };
        int d[52][52] = { 0 };
        for (int j = 0; j < K; j++) {
            cin >> a >> b;
            c[a + 1][b + 1] = 1;
        }
        deque<pair<int,int>> e;
        s = 0;
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= M; k++) {
                if (c[j][k] == 0 || d[j][k] == 1)continue;
                e.push_back(pair<int, int>(j, k));
                d[j][k] = 1;
                while (!e.empty()) {
                    int ef = e.front().first, es = e.front().second;
                    if (c[ef - 1][es] == 1 && d[ef - 1][es] == 0) {
                        d[ef - 1][es] = 1;
                        e.push_back(pair<int, int>(ef - 1, es));
                    }
                    if (c[ef][es - 1] == 1 && d[ef][es - 1] == 0) {
                        d[ef][es - 1] = 1;
                        e.push_back(pair<int, int>(ef, es - 1));
                    }
                    if (c[ef + 1][es] == 1 && d[ef + 1][es] == 0) {
                        d[ef + 1][es] = 1;
                        e.push_back(pair<int, int>(ef + 1, es));
                    }
                    if (c[ef][es + 1] == 1 && d[ef][es + 1] == 0) {
                        d[ef][es + 1] = 1;
                        e.push_back(pair<int, int>(ef, es + 1));
                    }
                    e.pop_front();
                }
                s++;
            }
        }
        cout << s << "\n";
    }

}

