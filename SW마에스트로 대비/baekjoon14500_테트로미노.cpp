#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int N, M, a[502][502] = { 0 }, b[502][502], s = 0;
deque<pair<int,int>> d;

void z(int i, int j) {
    d.push_back(pair<int, int>(i, j));
    if (d.size() == 4) {
        int e = a[d[0].first][d[0].second] + a[d[1].first][d[1].second] + 
            a[d[2].first][d[2].second] + a[d[3].first][d[3].second];
        //s = e > s ? e : s;
        if (e > s) {
            s = e;
            for (int i = 0; i < 4; i++) {
                cout << d[i].first << d[i].second << endl;
            }
        }
        return;
    }
    if (d.size() == 3) {
        if (d[0].second == d[1].second && d[0].first != i && d[0].second < M) {
            z(d[0].first, d[0].second + 1);
            d.pop_back();
        }
        if (d[0].first == d[1].first && d[0].second != j && d[0].first < N) {
            z(d[0].first + 1, d[0].second);
            d.pop_back();
        }
        if (d[1].first != i && d[1].second < M) {
            z(d[1].first, d[1].second + 1);
            d.pop_back();
        }
        if (d[1].first != d[0].first && d[1].second > 1 && d[1].second - 1 != j) {
            z(d[1].first, d[1].second - 1);
            d.pop_back();
        }
        if (d[1].first == i && d[1].first < N) {
            z(d[1].first + 1, d[1].second);
            d.pop_back();
        }
        if (j < M && j + 1 != d[1].second) {
            z(i, j + 1);
            d.pop_back();
        }
        if (d[1].second != j - 1 && d[0].first != i && j > 1) {
            z(i, j - 1);
            d.pop_back();
        }
        if (i < N) {
            z(i + 1, j);
            d.pop_back();
        }
    }
    else if (d.size() == 2) {
        if (d[0].first == i) {
            if (j < M) {
                z(i, j + 1);
                d.pop_back();
            }
            if (i < N) {
                z(i + 1, j);
                d.pop_back();
                z(i + 1, j - 1);
                d.pop_back();
            }
        }
        else {
            if (j < M) {
                z(i, j + 1);
                d.pop_back();
                z(i - 1, j + 1);
                d.pop_back();
            }
            if (i < N) {
                z(i + 1, j);
                d.pop_back();
            }
            if (j > 1) {
                z(i, j - 1);
                d.pop_back();
            }
        }
    }
    else if (d.size() == 1) {
        if (j < M) {
            z(i, j + 1);
            d.pop_back();
        }
        if (i < N) {
            z(i + 1, j);
            d.pop_back();
        }
        d.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            z(i, j);
        }
    }
    //z(1, 3);
    cout << d.size();
    cout << s;
}

