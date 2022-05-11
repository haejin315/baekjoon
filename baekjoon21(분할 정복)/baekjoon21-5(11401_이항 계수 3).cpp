
#include <iostream>

using namespace std;

long long N2, K;
long long C = 1000000007;
constexpr int d = 100000;
long long arr[d];

long long power(long long N, int len) {
    long long a, b;
    if (len == 1) return N % C;
    if (len == 2) return (N * N) % C;
    else {
        if (len < d && arr[len / 2] != -1) a = arr[len / 2];
        else {
            a = power(N, len / 2);
            if (len < d) arr[len / 2] = a;
        }
        if (len < d && arr[len - len / 2] != -1) b = arr[len - len / 2];
        else {
            b = power(N, len - len / 2);
            if (len < d) arr[len - len / 2] = b;
        }
    }
    return (a * b) % C;
}

long long fac(int len) {
    long long ans = 1;
    for (int i = 2; i <= len; i++) {
        ans = (ans * i) % C;
    }
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    fill_n(arr, 100000, -1);
    cin >> N2 >> K;
    cout << (fac(N2) * power((fac(K) * fac(N2 - K)) % C, C - 2)) % C;
}

