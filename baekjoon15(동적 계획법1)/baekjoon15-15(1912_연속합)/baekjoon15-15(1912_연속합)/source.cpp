
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, b, c;
    cin >> n;
    int* a = new int[n + 1];
    a[0] = 0;
    c = -1001;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        if (a[i - 1] <= 0) {
            a[i] = b;
        }
        else {
            a[i] = a[i - 1] + b;
        }
        if (a[i] > c)c = a[i];
    }
    cout << c;
}

