
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int T, x1, y1, x2, y2, n, a, b, d, e, ans;
    int c[50][3];
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        ans = 0;
        for (int j = 0; j < n; j++) {
            cin >> c[j][0] >> c[j][1] >> c[j][2];
            a = x1 - c[j][0];
            b = y1 - c[j][1];
            d = x2 - c[j][0];
            e = y2 - c[j][1];
            if (a * a + b * b < c[j][2] * c[j][2] && d * d + e * e > c[j][2] * c[j][2] ||
                a * a + b * b > c[j][2] * c[j][2] && d * d + e * e < c[j][2] * c[j][2]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}

