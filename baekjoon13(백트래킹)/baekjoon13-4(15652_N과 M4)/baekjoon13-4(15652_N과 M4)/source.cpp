#include <iostream>

using namespace std;


int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int a[7] = { 0 };
    int b[7] = { 0 };
    int c = 1;
    while (1) {
        for (int i = 0; i < M; i++) {
            cout << a[i] + 1 << " ";
        }
        cout << "\n";
        int c = M - 1;
        a[c]++;
        while (1) {
            if (a[0] >= N) {
                return 0;
            }
            else if (a[c] >= N) {
                a[c - 1]++;
                for (int i = c; i < M; i++) {
                    a[i] = a[c - 1];
                }
                c--;
            }
            else {
                break;
            }
        }
    }
}
