#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

map<string, string> parent;
map<string, int> friendnum;

string ufind(string x) {
    if (x == parent[x])return x;
    return parent[x] = ufind(parent[x]);
}

void umerge(string x, string y) {
    x = ufind(x);
    y = ufind(y);
    if (x == y)return;
    parent[y] = x;
}

bool isUnion(string x, string y) {
    x = ufind(x);
    y = ufind(y);
    if (x == y)return 1;
    return 0;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T, F;
    string a, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> F;
        for (int j = 0; j < F; j++) {
            cin >> a >> b;
            if (parent[a] == "") {
                parent[a] = a;
                friendnum[a] = 1;
            }
            if (parent[b] == "") {
                parent[b] = b;
                friendnum[b] = 1;
            }
            if (!isUnion(a, b)) {
                friendnum[ufind(a)] += friendnum[ufind(b)];
                umerge(a, b);
            }
            cout << friendnum[ufind(a)] << "\n";
        }
    }
    
}

