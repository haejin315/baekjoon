
#include <iostream>

using namespace std;

int fac(int a) {
    if (a == 0)return 1;
    return a * fac(a - 1);
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    cout << fac(N);
}

