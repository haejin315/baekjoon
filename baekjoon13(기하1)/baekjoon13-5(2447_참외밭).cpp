
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int K, a = 0, b = 0, check = 0;
    int arr[6][2] = { 0 }, count[5] = { 0 }, ans[4] = { 0 };
    cin >> K;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        count[arr[i][0]]++;
    } 
    for (int i = 1; i < 5; i++) {
        if (count[i] == 2) {
            if (a == 0)a = i;
            else b = i;
        }
    }
    if ((a == 1 && b == 4) || (a == 2 && b == 3)) {
        a ^= b; b ^= a; a ^= b;
    }
    cout << a << b << endl;
    for (int i = 0; i < 6; i++) {
        if (arr[i][0] != a && arr[i][0] != b) {
            check = 1;
            if (ans[0] == 0)ans[0] = arr[i][1];
            else ans[1] = arr[i][1];
        }
        else if (arr[i][0] == a) {
            if (check == 0 && ans[2] != 0)continue;
            ans[2] = arr[i][1];
            if (i != 5) ans[3] = arr[i + 1][1];
            else ans[3] = arr[0][1];
            check = 0;
        }
        cout << ans[0] << ans[1] << ans[2] << ans[3] << endl;
    }
    cout << K * (ans[0] * ans[1] - ans[2] * ans[3]);
}

