
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, K, a;
    cin >> N >> K;
    a = 1;
    for (int i = 0; i < K; i++) {
        a *= N - i;
        a /= i + 1;
    }
    cout << a;
}

