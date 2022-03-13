
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, K, ans;
    cin >> N >> K;
    int a[10];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (a[i] <= K) {
            K -= a[i];
            ans++;
            if (a[i] <= K) {
                i++;
            }
        }
    }
    cout << ans;
}

