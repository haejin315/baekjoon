#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int a[1000][1000] = { 0 };

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M, N;
    cin >> M >> N;

    int b = 1, c = -1;
    vector<pair<int, int>> d1, d2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)d1.push_back(make_pair(i, j));
        }
    }
    while (1) {
        if (d1.empty() && d2.empty())break;
        if (b == 1) {
            while (!d1.empty()) {
                int e = d1.back().first, f = d1.back().second;
                if (e + 1 < N && a[e + 1][f] == 0) {
                    a[e + 1][f] = 1;
                    d2.push_back(make_pair(e + 1, f));
                }
                if (f + 1 < M && a[e][f + 1] == 0) {
                    a[e][f + 1] = 1;
                    d2.push_back(make_pair(e, f + 1));
                }
                if (e - 1 >= 0 && a[e - 1][f] == 0) {
                    a[e - 1][f] = 1;
                    d2.push_back(make_pair(e - 1, f));
                }
                if (f - 1 >= 0 && a[e][f - 1] == 0) {
                    a[e][f - 1] = 1;
                    d2.push_back(make_pair(e, f - 1));
                }
                d1.pop_back();
            }
            c++;
            b = 2;
        }
        else if (b == 2) {
            while (!d2.empty()) {
                int e = d2.back().first, f = d2.back().second;
                if (e + 1 < N && a[e + 1][f] == 0) {
                    a[e + 1][f] = 1;
                    d1.push_back(make_pair(e + 1, f));
                }
                if (f + 1 < M && a[e][f + 1] == 0) {
                    a[e][f + 1] = 1;
                    d1.push_back(make_pair(e, f + 1));
                }
                if (e - 1 >= 0 && a[e - 1][f] == 0) {
                    a[e - 1][f] = 1;
                    d1.push_back(make_pair(e - 1, f));
                }
                if (f - 1 >= 0 && a[e][f - 1] == 0) {
                    a[e][f - 1] = 1;
                    d1.push_back(make_pair(e, f - 1));
                }
                d2.pop_back();
            }
            c++;
            b = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << c;
    
}

