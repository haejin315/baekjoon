#include <iostream>

using namespace std;

int a[9] = { 1 };
int N, M;
void z(int b) {
    if (b == M + 1) {
        for (int i = 1; i <= M; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = a[b - 1]; i <= N; i++) {
        a[b] = i;
        z(b + 1);
    }
}

int main()
{
    cin >> N >> M;
    z(1);
}

