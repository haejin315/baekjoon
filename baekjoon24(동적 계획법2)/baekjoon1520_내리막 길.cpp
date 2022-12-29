#include <iostream>
#include <algorithm>

using namespace std;

int a[502][502] = { 0 };
int b[502][502] = { 0 };
int c[502][502] = { 0 };
int N, M;

int line(int n, int m) {
    if (a[n][m - 1] < a[n][m]) {
        if (b[n][m - 1] == 0) {
            c[n][m] += line(n, m - 1);
        }
        else {
            c[n][m] += c[n][m - 1];
        }
    }
    if (a[n - 1][m] < a[n][m]) {
        if (b[n - 1][m] == 0) {
            c[n][m] += line(n - 1, m);
        }
        else {
            c[n][m] += c[n - 1][m];
        }
    }
    if (a[n][m + 1] < a[n][m]) {
        if (b[n][m + 1] == 0) {
            c[n][m] += line(n, m + 1);
        }
        else {
            c[n][m] += c[n][m + 1];
        }
    }
    if (a[n + 1][m] < a[n][m]) {
        if (b[n + 1][m] == 0) {
            c[n][m] += line(n + 1, m);
        }
        else {
            c[n][m] += c[n + 1][m];
        }
    }


    if (n == N && m == M) {
        return 1;
    }

    b[n][m] = 1;
    return c[n][m];

}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < N + 2; i++) {
        a[i][0] = 10001;
        a[i][M + 1] = 10001;
    }
    for (int i = 0; i < M + 2; i++) {
        a[0][i] = 10001;
        a[N + 1][i] = 10001;
    }
    if (N == 1 && M == 1) {
        cout << 1;
        return 1;
    }
    line(1, 1);


    cout << c[1][1];
}

