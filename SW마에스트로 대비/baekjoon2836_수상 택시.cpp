#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <math.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M, a, b, big;
    vector<pair<int,int>> right;
    vector<pair<int,int>> left;
    cin >> N >> M;
    big = M;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a == b)continue;
        else if (a > b) {
            left.push_back({ b,a });
            if (a > big)big = a;
        }
        else {
            right.push_back({ a,b });
            if (b > big)big = b;
        }
    }

    int start, end;
    if (!left.empty()) {
        sort(left.begin(), left.end());
        start = left[0].first, end = left[0].second;
    }

    int s = 2 * big - M;
    
    for (int i = 1; i < left.size(); i++) {
        if (left[i].first > M) {
            if (left[i].second < M) {
                s += 2 * (M - left[i].second);
            }
            break;
        }
        if (left[i].first <= end)end = end > left[i].second ? end : left[i].second;
        else {
            if (end > M)end = M;
            s += 2 * (end - start);
            start = left[i].first;
            end = left[i].second;
        }
    }
    if (!left.empty()) {
        if (end > M)end = M;
        if (start > M)start = M;
        s += 2 * (end - start);
    }
    cout << s;

}

