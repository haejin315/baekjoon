
#include <iostream>

using namespace std;

int pivo(int a) {
    if (a == 0)return 0;
    if (a == 1)return 1;
    return pivo(a - 1) + pivo(a - 2);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    cout << pivo(n);
}
