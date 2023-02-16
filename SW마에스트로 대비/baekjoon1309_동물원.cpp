#include <iostream>

using namespace std;

int lion[100001] = { 0 };

int main()
{
    int N, s = 3;
    cin >> N;
    int a[100001] = { 0 };
    a[1] = 1;
    for (int i = 2; i <= N; i++) {
        a[i] = (s - a[i - 1]) % 9901;
        s = (s + 2 * a[i]) % 9901;
    }
    cout << (s + 9901) % 9901;
}

