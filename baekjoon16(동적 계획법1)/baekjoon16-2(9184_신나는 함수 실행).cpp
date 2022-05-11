
#include <iostream>

using namespace std;

int a[51][51][51] = { 0 };
int a1, a2, a3, a4;

int w(int b1, int b2, int b3) {
    if (b1 <= 0 || b2 <= 0 || b3 <= 0) {
        a[b1][b2][b3] = 1;
        return 1;
    }
    if (b1 > 20 || b2 > 20 || b3 > 20) {
        a4 = 20;
        w(20, 20, 20);
        return 1;
    }
    if (b1 < b2 && b2 < b3) {
        if (a[b1][b2][b3 - 1] != 0 && a[b1][b2 - 1][b3 - 1] != 0 && a[b1][b2 - 1][b3] != 0) {
            a[b1][b2][b3] = a[b1][b2][b3 - 1] + a[b1][b2 - 1][b3 - 1] - a[b1][b2 - 1][b3];
            return a[b1][b2][b3];
        }
        a[b1][b2][b3] = w(b1, b2, b3 - 1) + w(b1, b2 - 1, b3 - 1) - w(b1, b2 - 1, b3);
        return a[b1][b2][b3];
    }
    else {
        if (a[b1 - 1][b2][b3] != 0 && a[b1 - 1][b2 - 1][b3] != 0 &&
            a[b1 - 1][b2][b3 - 1] != 0 && a[b1 - 1][b2 - 1][b3 - 1] != 0) {
            a[b1][b2][b3] = a[b1 - 1][b2][b3] + a[b1 - 1][b2 - 1][b3] +
                a[b1 - 1][b2][b3 - 1] - a[b1 - 1][b2 - 1][b3 - 1];
            return a[b1][b2][b3];
        }
        a[b1][b2][b3] = w(b1 - 1, b2, b3) + w(b1 - 1, b2 - 1, b3) + w(b1 - 1, b2, b3 - 1) - w(b1 - 1, b2 - 1, b3 - 1);
        return a[b1][b2][b3];
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    while (1) {
        cin >> a1 >> a2 >> a3;
        if (a1 == -1 && a2 == -1 && a3 == -1) break;
        a4 = 1;
        if (a1 <= 0 || a2 <= 0 || a3 <= 0) {
            cout << "w(" << a1 << ", " << a2 << ", " << a3 << ") = 1\n";
            continue;
        }
        a[0][0][0] = 1; a[0][0][1] = 1; a[0][1][0] = 1; a[1][0][0] = 1;
        a[0][1][1] = 1; a[1][0][1] = 1; a[1][1][0] = 1;
        w(a1, a2, a3);
        if (a4 == 20) {
            cout << "w(" << a1 << ", " << a2 << ", " << a3 << ") = " << a[20][20][20] << "\n";
        }
        else {
            cout << "w(" << a1 << ", " << a2 << ", " << a3 << ") = " << a[a1][a2][a3] << "\n";
        }
    }
}

