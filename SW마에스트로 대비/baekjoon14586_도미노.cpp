#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, a, b;
    cin >> N;
    vector<pair<int, int>> v;
    v.push_back({ -1,0 });
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());
    //cout << v[0].first;

    vector<int> v2(v.size(), 0);
    vector<pair<int, int>> v3;
    v2[0] = 0;
    v2[1] = 1;
    v3.push_back({ 0,0 });
    
    int bb = -1;
    for (int i = 1; i < v.size();i++) {
        if (v[i].first <= bb) {
            bb = bb > v[i].first + v[i].second ? bb : v[i].first + v[i].second;
            v3.push_back({ v3[i - 1].first, bb });
        }
        else {
            bb = v[i].first + v[i].second;
            v3.push_back({i, bb});
        }
    }
    //i가 왼쪽으로 쓰러뜨릴 수 있는 최대 도미노가 a개면 v2(i-a-1) + 1  후보
    //i를 오른쪽으로 쓰러뜨릴 수 있는 애들 k1~kn 중에서 v2(i-(k1~kn)) +1 이 최소인 놈이 후보
    //둘 중 최소가 i노드까지 최소

    for (int i = 2; i < v.size(); i++) {
        int k = i - 1;
        int small = v[i].first - v[i].second;
        while (1) {
            if (k == 0 || v[k].first < small)break;
            int sumLeft = v[k].first - v[k].second;
            small = small < sumLeft ? small : sumLeft;
            k--;
        }
        int s1 = v2[k] + 1, s2;
        
        int big = 400;

        for (int j = i - 1; j > 0; j--) {
            int k = j;
            int check = v[k].first + v[k].second;
            for (; k < i; k++) {
                if (v[k + 1].first > check)break;
                check = check > v[k + 1].first + v[k + 1].second ? check : v[k + 1].first + v[k + 1].second;
            }
            if (k == i) big = big < v2[j - 1] ? big : v2[j - 1];
        }
        s2 = big + 1;
        v2[i] = min(s1, s2);
    }
    cout << v2[N];
}

