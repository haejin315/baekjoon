
#include <iostream>

using namespace std;

long long a[100004][2];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, m1;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a[i][0];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i][1];
    }
    m1 = a[0][1];
    long long b, ans;
    b = a[0][0];
    ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (a[i][1] < m1) {
            ans += b * m1;
            b = a[i][0];
            m1 = a[i][1];
        }
        else {
            b += a[i][0];
        }
    }
    ans += b * m1;
    cout << ans;
}

