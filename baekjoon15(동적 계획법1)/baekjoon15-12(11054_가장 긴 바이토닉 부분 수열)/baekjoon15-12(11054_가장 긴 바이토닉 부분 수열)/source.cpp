
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, c, d, e;
    int a[1002][2] = { 0 };
    int b[1001] = { 0 };
    cin >> N;
    c = 0;
    d = N + 1;
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= N; i++) {
        if (b[i] > b[c]) {
            a[i][0] = a[c][0] + 1;
            c = i;
        }
        else {
            e = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (b[j] < b[i]) {
                    if (a[j][0] >= a[e][0])e = j;
                }
            }
            a[i][0] = a[e][0] + 1;
            if (a[i][0] >= a[c][0])c = i;
        }
    }
    for (int i = N; i >= 0; i--) {
        if (b[i] > b[d]) {
            a[i][1] = a[d][1] + 1;
            d = i;
        }
        else {
            e = 0;
            for (int j = i + 1; j < N + 2; j++) {
                if (b[j] < b[i]) {
                    if (a[j][1] >= a[e][1])e = j;
                }
            }
            a[i][1] = a[e][1] + 1;
            if (a[i][1] >= a[d][1])d = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i][0] + a[i][1] > ans)ans = a[i][0] + a[i][1];
    }
    cout << ans - 1;
}

