#include <iostream>
#include <algorithm>

using namespace std;



int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int M, a;
    int b[21] = { 0 };
    string c;

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> c;
        if (c == "add") {
            cin >> a;
            b[a] = 1;
        }
        else if (c == "remove") {
            cin >> a;
            b[a] = 0;
        }
        else if (c == "check") {
            cin >> a;
            if (b[a] == 1) {
                cout << "1\n";
            }
            else cout << "0\n";
        }
        else if (c == "toggle") {
            cin >> a;
            b[a] ^= 1;
        }
        else if (c == "all") {
            for (int j = 1; j <= 20; j++) {
                b[j] = 1;
            }
        }
        else if (c == "empty") {
            for (int j = 1; j <= 20; j++) {
                b[j] = 0;
            }
        }
    }
}

