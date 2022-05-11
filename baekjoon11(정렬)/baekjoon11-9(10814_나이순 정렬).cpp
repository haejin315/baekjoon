#include <iostream>
#include <string>

using namespace std;

string aa[100000][2];
string co[100000][2];

void merge(int a, int b) {
    int c = (a + b) / 2;
    if (b - a == 1) {
        return;
    }
    if (b - a == 2) {
        if (stoi(aa[a][0]) <= stoi(aa[c][0])) {
            return;
        }
        else {
            co[0][0] = aa[a][0];
            aa[a][0] = aa[c][0];
            aa[c][0] = co[0][0];
            co[0][1] = aa[a][1];
            aa[a][1] = aa[c][1];
            aa[c][1] = co[0][1];
            return;
        }
    }
    merge(a, c);
    merge(c, b);
    int start = a;
    int middle = c;
    for (int i = 0; i < b - start; i++) {
        if (a == middle) {
            co[i][0] = aa[c][0];
            co[i][1] = aa[c][1];
            c++;
        }
        else if (c == b) {
            co[i][0] = aa[a][0];
            co[i][1] = aa[a][1];
            a++;
        }
        else {
            if (stoi(aa[a][0]) <= stoi(aa[c][0])) {
                co[i][0] = aa[a][0];
                co[i][1] = aa[a][1];
                a++;
            }
            else {
                co[i][0] = aa[c][0];
                co[i][1] = aa[c][1];
                c++;
            }
        }
    }
    for (int i = 0; i < b - start; i++) {
        aa[i + start][0] = co[i][0];
        aa[i + start][1] = co[i][1];
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> aa[i][0] >> aa[i][1];
    }
    merge(0, N);
    for (int i = 0; i < N; i++) {
        cout << aa[i][0] << " " << aa[i][1] << "\n";
    }
}
