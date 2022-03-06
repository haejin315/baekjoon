
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, a, b, c;
    cin >> N;
    for (int j = 0; j < N; j++) {
        cin >> a >> b;
        c = 1;
        for (int i = 0; i < b; i++) {
            c = (c * a) % 10;
        }
        if (c == 0)c = 10;
        cout << c << "\n";
    }
}

