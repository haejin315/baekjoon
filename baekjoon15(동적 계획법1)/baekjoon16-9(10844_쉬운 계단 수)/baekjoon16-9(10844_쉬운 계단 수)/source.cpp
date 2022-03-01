
#include <iostream>

using namespace std;

int b = 1000000000;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int a[100][10] = {0};
    for (int i = 1; i < 10; i++) {
        a[0][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                a[i][j] = a[i - 1][j + 1];
            }
            else if (j == 9) {
                a[i][j] = a[i - 1][j - 1];
            }
            else {
                a[i][j] = (a[i - 1][j + 1] + a[i - 1][j - 1]) % b;
            }
        }
        
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = ans % b + a[N - 1][i];
    }
    cout << ans % b;
}

