
#include <iostream>
#include <memory.h>
using namespace std;

long long n, a, ans, d, c;
long long his1[100010];
long long his2[100010];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(1) {
        memset(his1, 0, 100010 * sizeof(long long));
        memset(his2, 0, 100010 * sizeof(long long));
        his1[0] = -1;
        cin >> n;
        if (n == 0)break;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> his1[i];
            if (his1[i] == his1[i - 1] && his1[i] == his1[i-2])his2[i] = his2[i - 1] + 1;
        }
        for (int i = 1; i <= n; i++) {
            a = his1[i];
            if (his1[i - 1] > a) {
                c = 1;
                while (his1[i - c] > a) {
                    d = his1[i - c] * c;
                    if (ans < d)ans = d;
                    his1[i - c] = a;
                    c += his2[i - c] + 1;
                }
                his2[i] = c - 2;
            }
        }
        c = 1;
        while (his1[n + 1 - c] > 0) {
            d = his1[n + 1 - c] * c;
            if (ans < d)ans = d;
            his1[n + 1 - c] = 1;
            c += his2[n + 1 - c] + 1;
        }
        cout << ans << "\n";
    }
}

