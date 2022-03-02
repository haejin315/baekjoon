
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n, b;
    cin >> n;
    int a[10001] = { 0 };
    int a1, a2;
    cin >> a[1];
    int c = 0;
    a1 = 0;
    a2 = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> b;
        if (c != 1) {
            a[i] = a[i - 1] + b;
            c++;
        }
        else {
            if (a[i - 3] + a2 >= a[i - 2] && a[i - 3] + a2 + b >= a[i - 1]) {
                a[i] = a[i - 3] + a2 + b;
                c = 1;
            }
            else if (a[i - 2] + b >= a[i - 1]) {
                a[i] = a[i - 2] + b;
                c = 0;
            }
            else {
                a[i] = a[i - 1];
                c = -1;
            }
        }
        a1 = a2;
        a2 = b;
    }
    cout << a[n];
}

