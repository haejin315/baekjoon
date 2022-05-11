
#include <iostream>

using namespace std;

int a[1110][1110] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    int b[4];
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> b[j];
        }
        cout << a[b[2]][b[3]] + a[b[0] - 1][b[1] - 1] - a[b[2]][b[1] - 1] - a[b[0] - 1][b[3]] << "\n";
    }
}

