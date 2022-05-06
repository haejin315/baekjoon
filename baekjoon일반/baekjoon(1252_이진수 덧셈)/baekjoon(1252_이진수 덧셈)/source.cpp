
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string a, b;
    int c[100], z = 0, z2 = 0;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '0')z++;
        else break;
    }
    a = a.substr(z, a.length());
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '0')z2++;
        else break;
    }
    b = b.substr(z2, b.length());

    int d = a.length() - 1, e = b.length() - 1,f = 0, check = 0;
    while (1) {
        if (d < 0 && e < 0)break;
        int g, h;
        if (d < 0)g = 0;
        else g = a[d] - 48;
        if (e < 0)h = 0;
        else h = b[e] - 48;
        if (g == 1 && h == 1) {
            c[f] = 0 + check;
            check = 1;
        }
        else if (g == 0 && h == 0) {
            c[f] = 0 + check;
            check = 0;
        }
        else {
            if (check == 0) {
                c[f] = 1;
                check = 0;
            }
            else {
                c[f] = 0;
                check = 1;
            }
        }
        f++;
        d--;
        e--;
    }
    if (check == 1)cout << 1;
    if (a.length() == 0 && b.length() == 0)cout << 0;
    for (int i = f - 1; i >= 0; i--) {
        cout << c[i];
    }

}

