
#include <iostream>

using namespace std;

int arrk[10010];
long long K, N, big, small, ans, ans2;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    big = 0;
    small = 1;
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arrk[i];
        if (arrk[i] > big)big = arrk[i];
    }
    ans = 0;
    ans2 = 0;
    long long mid;

    while (1) {
        ans = 0;
        mid = (small + big) / 2;
        for (int i = 0; i < K; i++) {
            ans += arrk[i] / mid;
            if (ans >= N)break;
        }
        if (ans >= N) {
            ans2 = mid;
            if (big <= small)break;
            small = mid + 1;
        }
        else {
            if (big <= small)break;
            big = mid - 1;
        }
    }
    cout << ans2;
}

