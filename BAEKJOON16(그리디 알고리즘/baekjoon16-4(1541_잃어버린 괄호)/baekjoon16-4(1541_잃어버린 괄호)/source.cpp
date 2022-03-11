
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    string a;
    int check = 0;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if (check == 0) {
            if (a[i] == '-') {
                check = 1;
            }
        }
        else {
            if (a[i] == '+') {
                a[i] = '-';
            }
        }
    }
    int b, c, ans;
    char y;
    b = 0;
   
    
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '+' || a[i] == '-') {
            b = i;
            y = a[i];
            break;
        }
    }
    if (b == 0) {
        cout << a;
        return 0;
    }
    ans = stoi(a.substr(0, b));
    for (int i = b + 1; i < a.length(); i++) {
        if (a[i]=='+'||a[i]=='-'|| i == a.length() -1) {
            int d = b - 1;
            if (i == a.length() - 1) {
                d = b;
            }
            c = stoi(a.substr(b + 1, i - d));
            if (y == '+') {
                ans += c;
            }
            else {
                ans -= c;
            }
            b = i;
            y = a[i];
        }
    }
    cout << ans;
}

