#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

void aa(int s[3]) {
    cout << s[0];
    s[0] = 5;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[1001] = { 0, 1, 3, 5 };

    for (int i = 4; i <= n; i++) {
        a[i] = (a[i - 2] * 2 + a[i - 1])%10007;
    }
    cout << a[n];
}

