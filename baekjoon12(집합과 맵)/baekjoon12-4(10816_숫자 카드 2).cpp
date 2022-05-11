
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> a;
vector<int> n;
int ans, ind1, ind2;

void ss1(int begin, int end, int target) {
    if (end - begin == 0) {
        if (n[end] == target)ind1 = end;
        return;
    }
    if (end - begin == 1) {
        if (n[begin] == target) {
            ind1 = begin; return;
        }
        if (n[end] == target) {
            ind1 = end; return;
        }
        return;
    }
    if (n[(begin + end) / 2] >= target) {
        ss1(begin, (begin + end) / 2, target);;
    }
    else {
        ss1((begin + end) / 2, end, target);
    }
}
void ss2(int begin, int end, int target) {
    if (end - begin == 0) {
        if (n[end] == target)ind2 = end;
        return;
    }
    if (end - begin == 1) {
        if (n[end] == target) {
            ind2 = end; return;
        }
        if (n[begin] == target) {
            ind2 = begin; return;
        }
        return;
    }
    if (n[(begin + end) / 2] > target) {
        ss2(begin, (begin + end) / 2, target);;
    }
    else {
        ss2((begin + end) / 2, end, target);
    }
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, b;
    cin >> N;
    n.push_back(-10000001);
    for (int i = 0; i < N; i++) {
        cin >> b;
        n.push_back(b);
    }
    sort(n.begin(), n.end());
    n.push_back(10000001);

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b;
        ind1 = -1;
        ind2 = -1;
        ans = 1;
        ss1(1, N, b);
        ss2(1, N, b);
        if (ind1 == -1) {
            cout << "0 ";
        }
        else {
            cout << ind2 - ind1 + 1 << " ";
        }

    }
}

