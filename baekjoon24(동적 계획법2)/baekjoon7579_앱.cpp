#include <iostream>
#include <algorithm>

using namespace std;

int a[101][2] = { 0 };
int b[101][10001] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, s = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0];
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i][1];

        s += a[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= s; j++) {
            if (j >= a[i][1]) {
                b[i][j] = max(b[i - 1][j], b[i - 1][j - a[i][1]] + a[i][0]);
            }
            else {
                b[i][j] = b[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= s; i++) {
        if (b[N][i] >= M) {
            cout << i;
            break;
        }
    }
}

