#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int N, s, p[10001][2] = {0};
    cin >> N >> p[1][0];
    p[1][1] = p[1][0];
    for (int i = 2; i <= N; i++) {
        cin >> p[i][0];
        s = p[i][0];
        for (int j = i / 2; j <= i; j++) {
            if (p[j][1] + p[i - j][0] > s)s = p[j][1] + p[i - j][0];
        }
        p[i][1] = s;
    }
    cout << p[N][1];
}

