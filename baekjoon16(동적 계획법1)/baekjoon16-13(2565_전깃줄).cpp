
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<pair<int, int>> a;
    int N;
    cin >> N;
    int b, c, f;
    int d[101] = { 0 };
    f = 0;
    a.push_back(pair<int, int>(0, 0));
    for (int i = 0; i < N; i++) {
        cin >> b >> c;
        a.push_back(pair<int, int>(b, c));
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= N; i++) {
        if (a[i].second > a[f].second) {
            d[i] = d[f] + 1;
            f = i;
        }
        else {
            int e = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[i].second > a[j].second) {
                    if (d[j] > d[e]) {
                        e = j;
                    }
                }
                d[i] = d[e] + 1;
                if (d[i] >= d[f]) {
                    f = i;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i] > ans)ans = d[i];
    }
    cout << N - ans;
}

