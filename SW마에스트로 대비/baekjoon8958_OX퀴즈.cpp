#include <iostream>

using namespace std;

int main()
{
    int n, s1, s2;
    cin >> n;
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s1 = 0;
        s2 = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == 'O') {
                s1++;
                s2 += s1;
            }
            else s1 = 0;
        }
        cout << s2 << "\n";
    }
}

