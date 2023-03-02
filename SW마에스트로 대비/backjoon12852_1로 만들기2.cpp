#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int b, a[1000001][2] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    
    cin >> b;
    
    for (int i = 2; i <= b; i++) {
        int m1 = a[i-1][0], m2 = b + 1, m3 = b + 1;
        if (i % 2 == 0)m2 = a[i / 2][0];
        if (i % 3 == 0)m3 = a[i / 3][0];
        int m = min(min(m1, m2), m3);
        a[i][0] = m + 1;
        if (m == m1)a[i][1] = 1;
        else if (m == m2)a[i][1] = 2;
        else if (m == m3)a[i][1] = 3;
    }

    cout << a[b][0] << "\n";
    while (1) {
        cout << b << " ";
        if (b == 1)break;
        if (a[b][1] == 1)b--;
        else if (a[b][1] == 2)b /= 2;
        else if (a[b][1] == 3)b /= 3;
    }


}

