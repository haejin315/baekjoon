#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int a[1000][10] = { 0 };
    int N, s = 0;
    cin >> N;
    for (int i = 0; i < 10; i++) {
        a[0][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k <= j; k++) {
                a[i][j] = (a[i][j] + a[i - 1][k]) % 10007;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        s = (s + a[N - 1][i]) % 10007;
    }
    cout << s;
}

