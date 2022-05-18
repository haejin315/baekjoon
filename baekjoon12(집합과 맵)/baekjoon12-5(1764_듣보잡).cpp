
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<string, int> a;
map<string, int> c;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    string b;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.insert({ b, 1 });
    }
    for (int i = 0; i < M; i++) {
        cin >> b;
        if (a[b] == 1)c.insert({ b, 1 });
    }
    int d = c.size();
    cout << d << "\n";
    map<string, int>::iterator j;
    for (j = c.begin(); j != c.end(); j++) {
        cout << j->first << "\n";
    }
}

