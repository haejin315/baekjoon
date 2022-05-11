
#include <iostream>

using namespace std;

int a[500];
int b[500];
int c[500];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n >> b[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[j];
        }
        for (int j = 0; j <= i; j++) {
            if (j == 0) c[0] = b[0] + a[0];
            else if (j == i)c[i] = b[i - 1] + a[i];
            else {
                if (b[j - 1] >= b[j])c[j] = b[j - 1] + a[j];
                else c[j] = b[j] + a[j];
            }
        }
        for (int j = 0; j <= i; j++) {
            b[j] = c[j];
        }
    }
    int d = -1;
    for (int j = 0; j < n; j++) {
        if (b[j] > d)d = b[j];
    }
    cout << d;
}

