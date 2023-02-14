#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, a, b[10001] = { 0 };
    deque<int> c;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        c.push_back(a);
    }
    sort(c.begin(), c.end());

    b[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (c[i] <= j)b[j] += b[j - c[i]];
        }
    }
    
    cout << b[k];
}

