
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    while (1) {
        stack<char> b;
        string a;
        getline(cin, a);
        if (a == ".") {
            break;
        }
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == '(' || a[i] == '[') {
                b.push(a[i]);
            }
            else if (a[i] == ')' || a[i] == ']') {
                if (b.size() == 0) {
                    cout << "no\n";
                    break;
                }
                else if (a[i] == ')') {
                    if (b.top() == '(') {
                        b.pop();
                    }
                    else {
                        cout << "no\n";
                        break;
                    }
                }
                else if (a[i] == ']') {
                    if (b.top() == '[') {
                        b.pop();
                    }
                    else {
                        cout << "no\n";
                        break;
                    }
                }
            }
            if (i == a.length() - 1 && b.size() == 0) {
                cout << "yes\n";
            }
            else if(i == a.length() - 1) {
               cout << "no\n";
            }
        }
    }
}

