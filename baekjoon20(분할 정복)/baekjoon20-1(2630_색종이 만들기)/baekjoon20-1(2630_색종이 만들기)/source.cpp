
#include <iostream>

using namespace std;

int white = 0;
int blue = 0;
int paper[128][128];

void square(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[x][y] != paper[i][j]) {
                square(x, y, size / 2);
                square(x, y + size / 2, size / 2);
                square(x + size / 2, y, size / 2);
                square(x + size / 2, y + size / 2, size / 2);
                return;
            }
        }
    }
    if (paper[x][y] == 0)white++;
    else blue++;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    square(0, 0, N);
    cout << white << "\n" << blue;
}

