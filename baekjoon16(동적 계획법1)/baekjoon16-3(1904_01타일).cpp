
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, b;
    cin >> N;
    if (N < 4)cout << N;
    else {
        int a[2] = { 2,3 };
        b = 1;
        for (int i = 4; i <= N; i++) {
            b = (b + 1) % 2;
            a[b] = (a[b] + a[(b + 1) % 2]) % 15746;
        }
        cout << a[b];
    }
}

