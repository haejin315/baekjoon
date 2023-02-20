#include <iostream>
#include <deque>

using namespace std;

deque<pair<int, int>> b[100001];
bool check[100001] = { 0 };
int lo = 0, s = 0, nn;

void find(int n) {
    for (int i = 0; i < b[n].size(); i++) {
        if (check[b[n][i].first] == 0) {
            lo += b[n][i].second;
            check[b[n][i].first] = 1;
            find(b[n][i].first);
            lo -= b[n][i].second;
        }
    }
    if (lo > s) {
        s = lo;
        nn = n;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int V, a1, a2, a3;

    cin >> V;
    for (int i = 0; i < V;) {
        cin >> a1;
        while (1) {
            cin >> a2;
            if (a2 == -1) {
                i++;
                break;
            }
            cin >> a3;
            b[a1].push_back({ a2,a3 });
        }
    }

    check[1] = 1;
    find(1);
    memset(check, 0, sizeof(check));
    lo = 0; s = 0;
    check[nn] = 1;
    find(nn);
    cout << s;
}

