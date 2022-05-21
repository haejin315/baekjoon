
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int W, H, X, Y, P, x, y, ans = 0;
    cin >> W >> H >> X >> Y >> P;
    for (int i = 0; i < P; i++) {
        cin >> x >> y;
        int a = x - X, b = y - Y - H / 2, c = x - X - W;
        if (a * a + b * b <= H * H / 4) {
            ans++;
        }
        else if (c * c + b * b <= H * H / 4) {
            ans++;
        }
        else if (x >= X && x <= X + W && y >= Y && y <= Y + H) {
            ans++;
        }
    }
    cout << ans;
}

