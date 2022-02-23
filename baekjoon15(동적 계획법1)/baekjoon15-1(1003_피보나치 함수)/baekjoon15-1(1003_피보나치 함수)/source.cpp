
#include <iostream>

using namespace std;

int a[3][2];
int c = 1;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int b, T;
    cin >> b;
    for (int d = 0; d < b; d++) {
        cin >> T;
        a[0][0] = 1; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 1;
        c = 1;
        if (T == 0) {
            cout << "1 0\n";
            continue;
        }
        else if (T == 1) {
            cout << "0 1\n";
            continue;
        }
        for (int i = 2; i <= T; i++) {
            c = (c + 1) % 3;
            a[c][0] = a[(c + 1) % 3][0] + a[(c + 2) % 3][0];
            a[c][1] = a[(c + 1) % 3][1] + a[(c + 2) % 3][1];
        }
        cout << a[c][0] << " " << a[c][1] << "\n";
    }
}

