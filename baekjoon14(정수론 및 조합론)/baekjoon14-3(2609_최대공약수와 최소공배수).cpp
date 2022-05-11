
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a, b, c, d, e;
    cin >> a >> b;
    if (a == b) {
        cout << a << "\n" << b;
        return 0;
    }
    d = a;
    e = b;
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    c = b;
    while (1) {
        c = a - b;
        if (a % c == 0) {
            break;
        }
        if (c > b) {
            a = c;
        }
        else {
            a = b;
            b = c;
        }
    }
    cout << c << "\n" << d * e / c;
}

