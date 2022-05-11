
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, a, b, c, a1, b1, c1;
    cin >> N;
    int a2 = 0;
    int b2 = 0;
    int c2 = 0;
    for (int i = 0; i < N; i++) {
        cin >> a1 >> b1 >> c1;
        if (b2 <= c2)a = a1 + b2;
        else a = a1 + c2;

        if (a2 <= b2)c = c1 + a2;
        else c = c1 + b2;

        if (a2 <= c2)b = b1 + a2;
        else b = b1 + c2;

        a2 = a;
        b2 = b;
        c2 = c;
    }
    if (a2 <= b2 && a2 <= c2)cout << a2;
    else if(b2 <= c2) cout << b2;
    else cout << c2;

}

