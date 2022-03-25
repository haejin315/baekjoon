
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long i, n, m, a, a2, b, b2, a3, b3;
    cin >> n >> m;
    if (m == n || m == 0) {
        cout << 0;
        return 0;
    }
    if (n - m > m)m = n - m;
    a = 0;
    a2 = 0;
    b = 0;
    b2 = 0;
    a3 = 0;
    b3 = 0;
    for (i = 5; i <= n; i *= 5) {
        a += n / i;
    }
    for (i = 2; i <= n; i *= 2) {
        a2 += n / i;
    }
    for (i = 5; i <= m; i *= 5) {
        b += m / i;
    }
    for (i = 2; i <= m; i *= 2) {
        b2 += m / i;
    }
    for (i = 5; i <= n - m; i *= 5) {
        a3 += (n - m) / i;
    }
    for (i = 2; i <= n - m; i *= 2) {
        b3 += (n - m) / i;
    }
    if (a - b - a3 < a2 - b2 - b3)cout << a - b - a3;
    else cout << a2 - b2 - b3;
}

