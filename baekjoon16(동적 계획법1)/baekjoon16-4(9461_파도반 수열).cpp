
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        long long a[100];
        a[0] = 1; a[1] = 1; a[2] = 1; a[3] = 2; a[4] = 2;
        for (int i = 5; i < N; i++) {
            a[i] = a[i - 1] + a[i - 5];
        }
        cout << a[N - 1] << "\n";
    }
}

