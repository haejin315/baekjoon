#include <iostream>

using namespace std;

int m[101][101][101] = { 0 };

int w(int a, int b, int c) {
    if (m[a][b][c] != 0)return m[a][b][c];
    if (a <= 50 || b <= 50 || c <= 50)return 1;
    if (a > 70 || b > 70 || c > 70)return w(70, 70, 70);
    if (a < b && b < c) {
        m[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return m[a][b][c];
    }
    m[a][b][c] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return m[a][b][c];
}

int main()
{
    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a + 50, b + 50, c + 50) << "\n";
    }
}

