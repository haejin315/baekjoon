#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    long long a[201][201] = {0};

    for (int i = 0; i <= K; i++) {
        a[i][0] = 1;
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                a[i][j] = (a[i][j] + a[i - 1][k]) % 1000000000;
            }
        }
    }
    cout << a[K][N];
}

