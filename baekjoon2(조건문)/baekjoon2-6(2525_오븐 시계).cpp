
#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int d = a + (b + c) / 60;
    if (d >= 24)d -= 24;
    cout << d << " " << (b + c) % 60;
}

