#include <iostream>

using namespace std;

int aa[1000000][3] = { 0 };
int co[1000000][3] = { 0 };

void merge(int a, int b, int xy) {
    int c = (a + b) / 2;
    if (b - a == 1) {
        return;
    }
    if (b - a == 2) {
        if (aa[a][xy] <= aa[c][xy]) {
            return;
        }
        else {
            aa[a][xy] ^= aa[c][xy];
            aa[c][xy] ^= aa[a][xy];
            aa[a][xy] ^= aa[c][xy];
            aa[a][(xy + 1) % 2] ^= aa[c][(xy + 1) % 2];
            aa[c][(xy + 1) % 2] ^= aa[a][(xy + 1) % 2];
            aa[a][(xy + 1) % 2] ^= aa[c][(xy + 1) % 2];
            aa[a][2] ^= aa[c][2];
            aa[c][2] ^= aa[a][2];
            aa[a][2] ^= aa[c][2];
            return;
        }
    }
    merge(a, c, xy);
    merge(c, b, xy);
    int start = a;
    int middle = c;
    for (int i = 0; i < b - start; i++) {
        if (a == middle) {
            co[i][xy] = aa[c][xy];
            co[i][(xy + 1) % 2] = aa[c][(xy + 1) % 2];
            co[i][2] = aa[c][2];
            c++;
        }
        else if (c == b) {
            co[i][xy] = aa[a][xy];
            co[i][(xy + 1) % 2] = aa[a][(xy + 1) % 2];
            co[i][2] = aa[a][2];
            a++;
        }
        else {
            if (aa[a][xy] <= aa[c][xy]) {
                co[i][xy] = aa[a][xy];
                co[i][(xy + 1) % 2] = aa[a][(xy + 1) % 2];
                co[i][2] = aa[a][2];
                a++;
            }
            else {
                co[i][xy] = aa[c][xy];
                co[i][(xy + 1) % 2] = aa[c][(xy + 1) % 2];
                co[i][2] = aa[c][2];
                c++;
            }
        }
    }
    for (int i = 0; i < b - start; i++) {
        aa[i + start][xy] = co[i][xy];
        aa[i + start][(xy + 1) % 2] = co[i][(xy + 1) % 2];
        aa[i + start][2] = co[i][2];
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> aa[i][0];
        aa[i][1] = i;
    }
    merge(0, N, 0);
    for (int i = 1; i < N; i++) {
        if (aa[i][0] != aa[i - 1][0]) {
            aa[i][2] = aa[i - 1][2] + 1;
        }
        else {
            aa[i][2] = aa[i - 1][2];
        }
    }
    merge(0, N, 1);
    for (int i = 0; i < N; i++) {
        cout << aa[i][2] << " ";
    }
}
