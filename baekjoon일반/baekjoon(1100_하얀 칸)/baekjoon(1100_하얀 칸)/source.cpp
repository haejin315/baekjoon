
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    char a;
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a;
            if ((i + j) % 2 == 0 && a == 'F') {
                ans++;
            }
        }
    }
    cout << ans;
}

