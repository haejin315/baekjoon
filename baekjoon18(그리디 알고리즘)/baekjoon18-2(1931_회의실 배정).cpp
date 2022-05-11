
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> a;

bool compare(pair<int, int> & v1, pair<int, int> & v2) {
    if (v1.second == v2.second) {
        return v1.first < v2.first;
    }
    return v1.second < v2.second;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, in1, in2, ans, co;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> in1 >> in2;
        a.push_back(pair<int, int>(in1, in2));
    }
    sort(a.begin(), a.end(), compare);
    ans = 0;
    co = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].first >= co) {
            co = a[i].second;
            ans++;
        }
    }
    cout << ans;
}

