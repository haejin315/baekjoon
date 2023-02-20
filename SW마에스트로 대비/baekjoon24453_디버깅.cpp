#include <iostream>
#include <queue>

using namespace std;

int a[500001] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, b, X, Y, s = 0;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> a[i];
    }
    a[M + 1] = N + 1;
    cin >> X >> Y;

    priority_queue<int, vector<int>, greater<int>> f;

    int k1 = Y + 1, k2 = 0;
    while (1) {
        //cout << k1 << k2 << endl << a[k1] << a[k2] << endl;
        if (a[k1] - a[k2] - 1>= X) {
            f.push(k1 - k2 - 1);
            if (k1 - k2 - 1 == Y)break;
            k2++;
        }
        else {
            k1++;
        }
        if (k1 > M + 1)break;
    }
    cout << M - f.top();
}

