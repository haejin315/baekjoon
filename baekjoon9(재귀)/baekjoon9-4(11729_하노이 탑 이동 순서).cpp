
#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int num, int a, int b, int c) {
    if (num == 1)cout << a << " " << c << "\n";
    else {
        hanoi(num - 1, a, c, b);
        cout << a << " " << c << "\n";
        hanoi(num - 1, b, a, c);
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int sum = 1;
    for (int i = 0; i < N; i++) {
        sum *= 2;
    }
    cout << sum - 1 << "\n";
    hanoi(N, 1, 2, 3);
}
