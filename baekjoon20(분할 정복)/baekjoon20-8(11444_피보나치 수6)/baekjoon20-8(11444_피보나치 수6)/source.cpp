
#include <iostream>
#include <map>

using namespace std;

constexpr int siz = 200000000;
constexpr int mod = 1000000007;
map<long long, long long> arr;

long long fibo(long long m) {
    if (arr.find(m) != arr.end()) {
        return arr[m];
    }
    else {
        long long a1 = fibo(m / 2);
        long long a2 = fibo(m / 2 - 1);
        if(m%2==0){
            long long a = ((a2 * a1) % mod + (a1 * (a1 + a2)) % mod) % mod;
            
                arr.insert(make_pair(m, a));
            
            return a;
        }
        else {
            long long a3 = a1 + a2;
            long long a = ((a1 * a1) % mod + (a3 * a3) % mod) % mod;
            
                arr.insert(make_pair(m, a));
            
            return a;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    arr.insert(make_pair(0, 0)); arr.insert(make_pair(1, 1));
    cout << fibo(n);
}

