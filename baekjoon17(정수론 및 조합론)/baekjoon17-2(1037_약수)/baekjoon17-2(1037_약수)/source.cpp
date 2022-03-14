
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, b;
    cin >> N;
    vector<int> a;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[N - 1];
}

