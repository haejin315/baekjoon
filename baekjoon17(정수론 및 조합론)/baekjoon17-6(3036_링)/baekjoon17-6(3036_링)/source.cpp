
#include <iostream>

using namespace std;

int mindivisor(int big, int small) {
    int r;
    if (big < small) {
        big ^= small;
        small ^= big;
        big ^= small;
    }
    while (1) {
        if (big % small == 0) {
            break;
        }
        r = big - small;
        if (r > small) {
            big = r;
        }
        else {
            big = small;
            small = r;
        }
    }
    return small;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, b;
    cin >> N;
    int a[100] = { 0 };
    cin >> a[0];
    for (int i = 1; i < N; i++) {
        cin >> a[i];
        b = mindivisor(a[0], a[i]);
        cout << a[0] / b << "/" << a[i] / b << "\n";
    }
}

