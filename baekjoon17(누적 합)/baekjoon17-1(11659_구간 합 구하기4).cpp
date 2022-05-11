
#include <iostream>
#include <map>

using namespace std;

int a[100100][2] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, sumstart, sumend;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0];
        a[i][1] = a[i - 1][1] + a[i][0];
    }
    for (int i = 0; i < M; i++) {
        cin >> sumstart >> sumend;
        cout << a[sumend][1] - a[sumstart - 1][1] << "\n";
    }
}

