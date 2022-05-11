
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a[10] = { 0 };
    string b;
    cin >> b;
    for (int i = 0; i < b.length(); i++) {
        a[b[i] - 48]++;
    }
    for (int i = 9; i >= 0; i--) {
        if (a[i] != 0) {
            cout << i;
            a[i]--;
            i++;
        }
    }
}
