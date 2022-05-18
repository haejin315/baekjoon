
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, W, H, a, b;
    cin >> N >> W >> H;
    b = sqrt(W * W + H * H);
    for (int i = 0; i < N; i++) {
        cin >> a;
        if (a <= b)cout << "DA\n";
        else cout << "NE\n";
    }
}

