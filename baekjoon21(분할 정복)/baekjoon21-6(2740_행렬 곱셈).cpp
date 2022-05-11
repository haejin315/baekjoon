
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M;
    int nm[100][100];
    int mk[100][100];
    int ans[100][100] = { 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> nm[i][j];
        }
    }
    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> mk[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                ans[i][j] += nm[i][k] * mk[k][j];
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

