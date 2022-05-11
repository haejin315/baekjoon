
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, a, b;
    a = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        b = i;
        while (1) {
            if (b % 5 != 0)break;
            a++;
            b /= 5;
        }
    }
    cout << a;
}

