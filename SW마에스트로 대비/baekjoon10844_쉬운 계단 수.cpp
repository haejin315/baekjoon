#include <iostream>

using namespace std;

#define mod 1000000000;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, a[101][10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, s = 0;
    cin >> N;
    for (int i = 1; i < N; i++) {
        a[i][0] = a[i - 1][1];
        a[i][9] = a[i - 1][8];
        for (int j = 1; j < 9; j++) {
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % mod;
        }
    }

    for (int i = 0; i < 10; i++) {
        s = (s + a[N - 1][i]) % mod;
    }
    cout << s;
}

