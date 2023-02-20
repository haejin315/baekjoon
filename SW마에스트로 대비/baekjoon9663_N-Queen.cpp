#include <iostream>

using namespace std;

int N, s = 0;
int a[15][2] = { 0 }, b[29][2] = { 0 };
int m[15][15] = { 0 };

void q(int c) {
    if (c == N) {
        s++;
        return;
    }
    for (int j = 0; j < N; j++) {
        if (m[c][j] == 0 && a[c][0] == 0 && a[j][1] == 0 && b[c + j - 1][0] == 0 && b[N - c + j - 1][1] == 0) {
            m[c][j] = 1;
            a[c][0] = 1;
            a[j][1] = 1;
            b[c + j - 1][0] = 1;
            b[N - c + j - 1][1] = 1;

            q(c + 1);
            m[c][j] = 0;
            a[c][0] = 0;
            a[j][1] = 0;
            b[c + j - 1][0] = 0;
            b[N - c + j - 1][1] = 0;

        }
    }
}

int main()
{
    cin >> N;
    
    q(0);
    cout << s;
}

