
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> a;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    string b, c;
    cin >> b;
    for (int i = 1; i <= b.length(); i++) {
        for (int j = 0; j <= b.length() - i; j++) {
            c = b.substr(j, i);
            a[c] = 1;
        }
    }
    cout << a.size();
}

