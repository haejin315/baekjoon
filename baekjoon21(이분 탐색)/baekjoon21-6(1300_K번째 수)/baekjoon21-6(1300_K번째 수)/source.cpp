
#include <iostream>
#include <cmath>

using namespace std;

int count(int N, int num) {
    int re = 0;
    for (int i = 1; i <= N; i++) {
        re += min(N, (int)num / i);
    }
    return re;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, k;
    
    cin >> N >> k;
    long long begin, end, mid;
    begin = 1;
    end = 1000000000;
    int ans;  
    while (1) {
        if (begin > end)break;
        mid = (begin + end) / 2;
        if (count(N, mid) >= k) {
            end = mid - 1;
            ans = mid;
        }
        else {
            begin = mid + 1;
        }
    }
    cout << ans;
}

