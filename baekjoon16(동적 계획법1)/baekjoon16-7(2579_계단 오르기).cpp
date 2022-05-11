
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a[300] = { 0 };
    int a2[300];
    int b = 0;
    int c;
    int n;
    cin >> n;
    cin >> a[0];
    a2[0] = a[0];
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    cin >> a[1];
    a2[1] = a[1];
    if (n == 2) {
        cout << a[0] + a[1];
        return 0;
    }
    cin >> a[2];
    a2[2] = a[2];
    if (a[0] >= a[1]) {
        a[2] += a[0];
        c = 0;
    }
    else {
        a[2] += a[1];
        c = 1;
    }
    a[1] += a[0];
    for (int i = 3; i < n; i++) {
        cin >> b;
        a2[i] = b;
        if (c == 1) {
            if (a[i - 3] + a2[i - 1] >= a[i - 2]) {
                a[i] = a[i - 3] + a2[i - 1] + b;
                c = 1;
            }
            else {
                a[i] = a[i - 2] + b;
                c = 0;
            }
        }
        else if (a[i - 1] >= a[i - 2]) {
            a[i] = a[i - 1] + b;
            c++;
        }
        else {
            a[i] = a[i - 2] + b;
            c = 0;
        }
    }
    
    cout << a[n - 1] << endl;
    
}

