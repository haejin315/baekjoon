
#include <iostream>

using namespace std;

int b[1001][1001];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, K, a;
    cin >> N >> K;
    a = N;
    b[0][0] = 1;
    if (N - K < K)K = N - K;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = (b[i - 1][j - 1] + b[i - 1][j]) % 10007;
            }
        }
    }
    cout << b[N][K];
}

