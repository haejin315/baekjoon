
#include <iostream>
#include <stack>

using namespace std;

int a[100011];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n, b, c;
    bool e = 0;
    stack<int> a;
    string d = "";
    cin >> n;
    b = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c >= b) {
            for (int j = b; j < c; j++) {
                a.push(j + 1);
                d += "+\n";
            }
            a.pop();
            d += "-\n";
            b = c;
        }
        else {
            if (c != a.top()) {
                e = 1;
            }
            else {
                a.pop();
                d += "-\n";
            }
        }
    }
    if (e == 1) {
        cout << "NO";
    }
    else cout << d;
}

