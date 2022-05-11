
#include <iostream>

using namespace std;

int a[10001] = { 0 };

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M;
        a[M]++;
    }
    int c = 1;
    int d = 0;
    int e = 0;
    while (e != N) {
        if (a[c] == 0) {
            c++;
            continue;
        }
        while (1) {
            if (a[c] == 0)break;
            cout << c << "\n";
            a[c]--;
            d++;
        }
        c++;
        e += d;
        d = 0;
    }
}
