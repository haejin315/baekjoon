
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, b, d;
    cin >> N;
    int a[1001][2] = { 0 };
    d = 0;
    b = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0];
        if (a[i][0] == a[b][0]) {
            a[i][1] = a[b][1];
        }
        else {
            for (int j = i - 1; j >= 0; j--) {
                if (a[j][0] < a[i][0]) {
                    if (a[d][1] < a[j][1]) {
                        d = j;
                    }
                }
            }
            a[i][1] = a[d][1] + 1;
            d = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i][1] > ans)ans = a[i][1];
    }
    cout << ans;
}

