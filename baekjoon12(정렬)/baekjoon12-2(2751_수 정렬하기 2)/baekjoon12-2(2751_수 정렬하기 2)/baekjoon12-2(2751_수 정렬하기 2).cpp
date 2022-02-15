
#include <iostream>

using namespace std;

int a[1000000];
int aa[1000000];

void merge(int b, int c) {
    int d = (c + b) / 2;
    if (c - b == 1) {
        return;
    }
    if (c - b == 2) {
        if (a[b] > a[d]) {
            a[b] ^= a[d];
            a[d] ^= a[b];
            a[b] ^= a[d];
            return;
        }
    }
    merge(b, d);
    merge(d, c);
    int bbb = b;
    int bb = b;
    int dd = d;
    while (1) {
        if (b == dd && d == c) { break; }
        else if (b == dd) {
            while (d != c) {
                aa[bb] = a[d];
                d++;
                bb++;
            }
        }
        else if (d == c) {
            while (b != dd) {
                aa[bb] = a[b];
                b++;
                bb++;
            }
        }
        else {
            if (a[b] > a[d]) {
                aa[bb] = a[d];
                d++;
                bb++;
            }
            else {
                aa[bb] = a[b];
                b++;
                bb++;
            }
        }
    }
    for (int i = bbb; i < c; i++) {
        a[i] = aa[i];
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    merge(0, N);
    for (int i = 0; i < N; i++) {
        cout << a[i] << "\n";
    }
}

