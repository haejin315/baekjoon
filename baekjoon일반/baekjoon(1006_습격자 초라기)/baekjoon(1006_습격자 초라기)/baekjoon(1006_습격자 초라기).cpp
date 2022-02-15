
#include <iostream>

using namespace std;
// 값, 인접구역3개, 현재구역이랑 공유가능한 인접구역개수, 현재구역 배치여부
int a[20001][6] = { 0 };

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T, N, W;
    cin >> N >> W;
    for (int i = 2; i < N; i++) {
        a[i][1] = i - 1;
        a[i][2] = i + 1;
        a[i][3] = i + N;
        a[i + 8][1] = i + N - 1;
        a[i + 8][2] = i + N + 1;
        a[i + 8][3] = i;
    }
    a[1][1] = N;
    a[1][2] = 2;
    a[1][3] = 1 + N;
    a[N][1] = N - 1;
    a[N][2] = 1;
    a[N][3] = 2 * N;
    a[1 + N][1] = 2 * N;
    a[1 + N][2] = N + 2;
    a[1 + N][3] = 1;
    a[2 * N][1] = 2 * N - 1;
    a[2 * N][2] = N + 1;
    a[2 * N][3] = N;


    for (int i = 1; i <= 2 * N; i++) {
        cin >> a[i][0];
    }
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j < 4; j++) {
            if (a[i][0] + a[a[i][j]][0] <= W) {
                a[i][4]++;
            }
        }
    }
    for (int i = 1; i <= 2 * N; i++) {
        cout << a[i][1] << " " << a[i][2] << " " << a[i][3] << " " << a[i][4] << "\n";
    }
}
