#include <iostream>
#include <deque>

using namespace std;

int a[1000001] = { 0 };

int main()
{
    a[1] = 1;
    a[2] = 2;
    int N;
    cin >> N;
    for (int i = 3; i <= N; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 15746;
    }
    cout << a[N];
}

