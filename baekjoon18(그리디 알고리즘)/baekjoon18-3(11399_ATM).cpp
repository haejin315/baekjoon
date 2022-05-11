
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, b, ans;
    cin >> N;
    vector<int> a;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.push_back(b);
    }
    ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) {
        ans += a[i] * (N - i);
    }
    cout << ans;
}

