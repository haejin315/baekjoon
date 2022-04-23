
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> house;
    int N, C, a, begin, end, ans, cur, pre, ans2;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> a;
        house.push_back(a);
    }
    sort(house.begin(), house.end());
    begin = 1;
    end = house.back();
    ans = 1;
    while (1) {
        if (begin > end)break;
        ans = (begin + end) / 2;
        cur = 1;
        pre = 0;
        for (a = 1; a < C;) {
            if (cur >= N) {
                a = -1;
                break;
            }
            if (house[cur] - house[pre] >= ans) {
                a++;
                pre = cur;
                cur++;
            }
            else {
                cur++;
            }
        }
        if (a == -1) {
            end = ans - 1;
        }
        else {
            begin = ans + 1;
            ans2 = ans;
        }
    }
    cout << ans2;
}

