
#include <iostream>

using namespace std;

long long A, B, C;
constexpr int d = 100000;
long long arr[d];

long long multipl(int len) {
    long long a, b;
    if (len == 1) return A % C;
    if (len == 2) return (A * A) % C;
    else {
        if (len < d && arr[len / 2] != -1) a = arr[len / 2];
        else {
            a = multipl(len / 2);
            if(len < d) arr[len / 2] = a;
        }
        if (len < d && arr[len - len / 2] != -1) b = arr[len - len / 2];
        else {
            b = multipl(len - len / 2);
            if(len < d) arr[len - len / 2] = b;
        }
    }
    return (a * b) % C;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    fill_n(arr, 100000, -1);
    cin >> A >> B >> C;
    
    cout << multipl(B);
}

