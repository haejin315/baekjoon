
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long N, M, start, end, mid, a, b, ans;
    end = 0;
    start = 0;
    ans = 0;
    int tree[1000010];
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (tree[i] > end)end = tree[i];
    }
    while (1) {
        a = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < N; i++) {
            if (tree[i] < mid)b = 0;
            else b = tree[i] - mid;
            a += b;
        }
        if (a >= M) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
        if (start > end)break;
    }
    cout << ans;
}

