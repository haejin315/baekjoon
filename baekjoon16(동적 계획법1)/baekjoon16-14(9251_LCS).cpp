
#include <iostream>
#include <string>

using namespace std;

int d[1001][1001] = { 0 };

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    string a, b, c;
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++) {
        if (b[0] == a[i]) {
            for (int j = i; j < a.length(); j++) {
                d[j][0] = 1;
            }
            break;
        }
        else {
            d[i][0] = 0;
        }
    }
    for (int i = 0; i < b.length(); i++) {
        if (a[0] == b[i]) {
            for (int j = i; j < b.length(); j++) {
                d[0][j] = 1;
            }
            break;
        }
        else {
            d[0][i] = 0;
        }
    }


    for (int i = 1; i < a.length(); i++) {
        for (int j = 1; j < b.length(); j++) {
            if (a[i] == b[j]) {
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else {
                if (d[i][j - 1] > d[i - 1][j]) {
                    d[i][j] = d[i][j - 1];
                }
                else {
                    d[i][j] = d[i - 1][j];
                }
            }
        }
    }
    cout << d[a.length() - 1][b.length() - 1];
}

