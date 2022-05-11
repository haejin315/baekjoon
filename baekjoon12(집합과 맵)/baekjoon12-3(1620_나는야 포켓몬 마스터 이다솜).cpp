
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> a;
string d[100100];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M, b;
    string c;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> c;
        a.insert({ c, i + 1 });
        d[i + 1] = c;
    }
    for (int i = 0; i < M; i++) {
        cin >> c;
        try {
            b = stoi(c);
            cout << d[b] << "\n";
        }
        catch (exception e) {
            cout << a[c] << "\n";
        }
    }
}

