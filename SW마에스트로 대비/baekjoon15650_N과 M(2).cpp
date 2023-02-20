#include <iostream>

using namespace std;

int a[9] = { 0 };
int N, M;
void z(int b) {
    if (b == M + 1) {
        for (int i = 1; i <= M; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = a[b - 1] + 1; i <= N; i++) {
        if (a[b] == 0) {
            a[b] = i;
            z(b + 1);
            a[b] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    z(1);
}

