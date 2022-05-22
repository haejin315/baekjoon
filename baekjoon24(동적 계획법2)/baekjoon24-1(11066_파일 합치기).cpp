
#include <iostream>
#include <memory.h>

using namespace std;

int T, K, file[500], dp[500][500] = { 0 }, file2[501] = { 0 };

int DP(int a, int b) {
    if (b - a == 0)return file[a];
    if (b - a == 1)return file[a] + file[b];
    if (dp[a][b] == 0) {
        int small = INT32_MAX;
        for (int i = a; i < b; i++) {
            int dd = DP(a, i) + DP(i + 1, b);
            if (i - a > 0)dd += file2[i + 1] - file2[a];
            if (b - i > 1)dd += file2[b + 1] - file2[i + 1];
            if (dd < small) {
                small = dd;
            }
        }
        dp[a][b] = small;
        return small;
    }
    else return dp[a][b];
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(dp, 0, sizeof(dp));
        cin >> K;
        cin >> file[0];
        if (K == 1) {
            cout << "0\n";
            continue;
        }
        file2[1] = file[0];
        for (int j = 1; j < K; j++) {
            cin >> file[j];
            file2[j + 1] = file2[j] + file[j];
        }
        cout << DP(0, K - 1) << "\n";
    }
}

