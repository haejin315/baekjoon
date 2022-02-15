
#include <iostream>

using namespace std;

int star(int a, int b, int k) {
    if (a % k >= k * 1 / 3 && a % k < k * 2 / 3 && b % k >= k * 1 / 3 && b % k < k * 2 / 3)return 0;
    if (k == 3)return 1;
    return star(a, b, k / 3);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (star(j, i, N) == 1)cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}
