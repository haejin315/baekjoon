
#include <iostream>
#include <string>

using namespace std;

string a[50][2];


int compare(int a1, int a2) {
    int c1 = 0;
    int d1 = 0;
    while (1) {
        if (c1 == a[a1][0].length() && d1 == a[a2][0].length()) {
            return 0;
        }
        if (a[a1][0][c1] > a[a2][0][d1]) {
            return 0;
        }
        else if (a[a1][0][c1] < a[a2][0][d1]) {
            return 1;
        }
        else {
            if (c1 + 1 == a[a1][0].length()) {
                if (a[a2][0][d1 + 1] > a[a1][0][0]) {
                    return 1;
                }
                if (a[a2][0][d1 + 1] < a[a1][0][0]) {
                    return 0;
                }
                c1 = 0;
                d1++;
            }
            else if (d1 + 1 == a[a2][0].length()) {
                if (a[a1][0][c1 + 1] < a[a2][0][0]) {
                    return 1;
                }
                if (a[a1][0][c1 + 1] > a[a2][0][00]) {
                    return 0;
                }
                d1 = 0;
                c1++;
            }
            else {
                c1++;
                d1++;
            }
        }
    }
}

void merge(int a1, int a2) {
    string f[50][2];
    int b = (a2 + a1) / 2;
    if (a2 - a1 == 1) {
        return;
    }
    if (a2 - a1 == 2) {
        if (compare(a1, b) == 0) {
            return;
        }
        else {
            f[b][0] = a[a1][0];
            f[b][1] = a[a1][1];
            a[a1][0] = a[b][0];
            a[a1][1] = a[b][1];
            a[b][0] = f[b][0];
            a[b][1] = f[b][1];
            return;
        }
    }
    merge(a1, b);
    merge(b, a2);
    int c = a1;
    int d = b;
    int e = a1;
    while (1) {
        if (e == a2) { break; }
        if (c == b) {
            for (int i = d; i < a2; i++) {
                f[e][0] = a[i][0];
                f[e][1] = a[i][1];
                e++;
            }
            break;
        }
        if (d == a2) {
            for (int i = c; i < b; i++) {
                f[e][0] = a[i][0];
                f[e][1] = a[i][1];
                e++;
            }
            break;
        }
        if (compare(c, d) == 0) {
            f[e][0] = a[c][0];
            f[e][1] = a[c][1];
            e++;
            c++;
        }
        else {
            f[e][0] = a[d][0];
            f[e][1] = a[d][1];
            e++;
            d++;
        }
    }
    for (int i = a1; i < a2; i++) {
        a[i][0] = f[i][0];
        a[i][1] = f[i][1];
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int K, N;
    cin >> K >> N;
    int b = 0;
    int len = 0;
    int lon = 0;
    for (int i = 0; i < K; i++) {
        cin >> a[i][0];
        if (a[i][0][0] > a[b][0][0])b = i;
        if (a[i][0].length() > a[lon][0].length())lon = i;
        else if (a[i][0].length() == a[lon][0].length()) {
            if (a[i][0] > a[lon][0])lon = i;
        }
        len += a[i][0].length();
        a[i][1] = "1";
    }
    a[lon][1] = to_string(N - K + 1);
    merge(0, K);
    for (int i = 0; i < K; i++) {
        for (int j = stoi(a[i][1]); j > 0; j--) {
            cout << a[i][0];
        }
    }
}
