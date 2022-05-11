
#include <iostream>
#include <vector>

using namespace std;

bool check[10];
int d[10];
int a[11];
vector<int> c;
int big = -1000000000;
int small = 1000000000;

void z(int m, int k) {
    if (m == k) {
        int e = a[0];
        for (int i = 0; i < c.size(); i++) {
            if (d[i] == 1) {
                e += a[i + 1];
            }
            else if (d[i] == 2) {
                e -= a[i + 1];
            }
            else if (d[i] == 3) {
                e *= a[i + 1];
            }
            else {
                e /= a[i + 1];
            }
        }
        if (e > big)big = e;
        if (e < small)small = e;
        return;
    }

    for (int i = 0; i < k; i++) {
        if (check[i] != 0)continue;
        check[i] = true;
        d[m] = c[i];
        z(m + 1, k);
        check[i] = false;
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int b;
    vector<int> d;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= 4; i++) {
        cin >> b;
        for (int j = 0; j < b; j++) {
            c.push_back(i);
        }
    }
    z(0, N - 1);
    cout << big << "\n" << small;
}

