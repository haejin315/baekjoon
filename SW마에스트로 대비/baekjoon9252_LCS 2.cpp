#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int a[1001][1001] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string b, c, s = "";
    cin >> b >> c;
    for (int i = 1; i <= b.length(); i++) {
        for (int j = 1; j <= c.length(); j++) {
            if (b[i - 1] == c[j - 1])a[i][j] = a[i - 1][j - 1] + 1;
            else a[i][j] = max(a[i][j - 1], a[i-1][j]);
        }
    }
    int d = b.length(), e = c.length();
    cout << a[d][e] << "\n";
    while (d > 0 && e > 0) {
        if (a[d-1][e] != a[d][e] && a[d - 1][e] == a[d][e - 1]) {
            s = b[d - 1] + s;
            d--;
            e--;
        }
        else {
            if (a[d - 1][e] > a[d][e - 1]) {
                d--;
            }
            else {
                e--;
            }
        }
    }

    cout << s;
}

