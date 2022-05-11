
#include <iostream>

using namespace std;

long long arr[1000010][2] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    long long remain[1010] = { 0 };
    cin >> arr[0][1];
    remain[arr[0][1] % M]++;
    for (int i = 1; i < N; i++) {
        cin >> arr[i][0];
        arr[i][1] = arr[i][0] + arr[i - 1][1];
        remain[arr[i][1] % M]++;
    }
    long long ans = 0;
    ans += remain[0];
    for (int i = 0; i < M; i++) {
        if (remain[i] == 0)continue;
        ans += remain[i] * (remain[i] - 1) / 2;
    }
    cout << ans;
}

