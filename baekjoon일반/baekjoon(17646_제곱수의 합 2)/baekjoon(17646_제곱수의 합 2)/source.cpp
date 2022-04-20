
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    long long n, m , t1, t2, t3, t4;
    cin >> m;
    n = m;
    while (n != 0) {
        t1 = floor(sqrt(n));
        n -= t1 * t1;
        cout << t1 << " " << n << endl;
    }

    cout << "\n\n";

    while (n != 0) {
        t1 = floor(sqrt(n));
        n -= t1 * t1;
        cout << t1 << " " << n << endl;
    }
}

