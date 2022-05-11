
#include <iostream>

using namespace std;

int a[30][30];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        if (M - N < N)N = M - N;
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= j; k++) {
                if (k == 0 || k == j)a[j][k] = 1;
                else a[j][k] = a[j - 1][k - 1] + a[j - 1][k];
            }
        }
        cout << a[M][N] << "\n";
    }
}

