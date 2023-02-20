#include <iostream>

using namespace std;

int a[9] = { 0 };
int b[9] = { 0 };
int N, M;

void c(int d) { 
    if (d > M) {
        for (int i = 1; i <= M; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (a[d] == 0) {
        for (int j = 1; j <= N; j++) {
            if (b[j] == 0) {
                a[d] = j;
                b[j] = d;

                c(d + 1);
                a[d] = 0;
                b[j] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    c(1);
}

