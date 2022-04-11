
#include <iostream>

using namespace std;

int paper[2200][2200];
int minus1 = 0;
int zero = 0;
int one = 0;

void devidePaper(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[x][y] != paper[i][j]) {
                int t = size / 3;
                for (int k1 = 0; k1 < 3; k1++) {
                    for (int k2 = 0; k2 < 3; k2++) {
                        devidePaper(x + k1 * t, y + k2 * t, t);
                    }
                }
                return;
            }
        }
    }
    if (paper[x][y] == -1) minus1++;
    else if (paper[x][y] == 0) zero++;
    else one++;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    devidePaper(0, 0, N);
    cout << minus1 << "\n" << zero << "\n" << one;
}

