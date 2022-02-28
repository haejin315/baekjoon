
#include <iostream>

using namespace std;

int a[1000001];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= N; i++) {
        if (i % 3 == 0 && i % 2 == 0) {
            if (a[i / 3] <= a[i / 2] && a[i / 3] <= a[i - 1]) {
                a[i] = a[i / 3] + 1;
            }
            else if (a[i / 2] <= a[i - 1]) {
                a[i] = a[i / 2] + 1;
            }
            else {
                a[i] = a[i - 1] + 1;
            }
        }
        else if (i % 3 == 0) {
            if (a[i / 3] <= a[i - 1]) {
                a[i] = a[i / 3] + 1;
            }
            else {
                a[i] = a[i - 1] + 1;
            }
        }
        else if (i % 2 == 0) {
            if (a[i / 2] <= a[i - 1]) {
                a[i] = a[i / 2] + 1;
            }
            else {
                a[i] = a[i - 1] + 1;
            }
        }
        else {
            a[i] = a[i - 1] + 1;
        }
    }
    cout << a[N];
}

