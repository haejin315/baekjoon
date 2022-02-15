
#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int a[10] = { 0 };
    int b = 1;
    int c;
    int d = N;
    int e;
    while (N / b >= 10) {
        b *= 10;
    }
    c = (d - d % b) / b;
    a[c] += d % b + 1;
    for (int i = 1; i < c; i++) {
        a[i] += b;
    }
    d = d % b;
    b /= 10;
    while (b > 0) {
        c = (d - d % b) / b;
        e = (N - (N % (b * 10))) / 10;
        for (int i = 0; i < c; i++) {
            a[i] += e + b;
        }
        a[c] += d % b + 1;
        a[c] += e;
        for (int i = c + 1; i <= 9; i++) {
            a[i] += e;
        }
        a[0] -= b;
        d = d % b;
        b /= 10;
    }

    for (int i = 0; i <= 9; i++) {
        cout << a[i] << " ";
    }
}
