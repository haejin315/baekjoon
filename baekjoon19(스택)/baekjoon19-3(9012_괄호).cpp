
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int T, d;
    char a;
    string c;
    d = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        stack<char> b;
        cin >> c;
        for (int j = 0; j < c.length(); j++) {
            if (b.size() == 0 && c[j] == ')') {
                cout << "NO\n";
                d = 1;
                break;
            }
            else if (c[j] == ')') {
                b.pop();
            }
            else if (c[j] == '(') {
                b.push('(');
            }
        }
        if (d == 1) {
            d = 0; 
            continue;
        }
        if (b.size() == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

