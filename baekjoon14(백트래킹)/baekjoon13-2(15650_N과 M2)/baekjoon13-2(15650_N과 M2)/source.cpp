#include <iostream>
#include <string.h>
using namespace std;

bool check(int* a, int len) {
    for (int i = 0; i < len; i++) {
        if (a[i] > 1)return 0;
    }
    return 1;
}

bool check2(int* a, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (a[i] >= a[i + 1]) { return 0; }
    }
    return 1;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int c[8] = { 0 };
    int d[8] = { 0 };
    for (int i = 0; i < M; i++) {
        c[i] = i + 1;
    }
    while (1) {
        int a = M - 1;
        memset(d, 0, sizeof(d));
        for (int i = 0; i < M; i++) {
            d[c[i] - 1]++;
        }
        if (check(d, N)) {
            if (check2(c, M)) {
                for (int i = 0; i < M; i++) {
                    cout << c[i] << " ";
                }
                cout << "\n";
            }
        }
        while (a >= 0) {
            c[a]++;
            if (c[0] > N) { break; }
            if (c[a] > N) {
                c[a] = 1;
            }
            else {
                break;
            }
            a--;
        }
        if (c[a] > N) {
            break;
        }
    }
}
