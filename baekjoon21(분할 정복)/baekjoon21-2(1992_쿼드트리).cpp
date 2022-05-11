
#include <iostream>

using namespace std;

int Tree[64][64];

void QuadTree(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (Tree[i][j] != Tree[x][y]) {
                cout << "(";
                int a = size / 2;
                QuadTree(x, y, a);
                QuadTree(x, y + a, a);
                QuadTree(x + a, y, a);
                QuadTree(x + a, y + a, a);
                cout << ")";
                return;
            }
        }
    }
    if (Tree[x][y] == 49)cout << "1";
    else cout << "0";
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    string b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        for (int j = 0; j < N; j++) {
            Tree[i][j] = b[j];
        }
    }
    QuadTree(0, 0, N);
}

