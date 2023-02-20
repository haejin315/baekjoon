#include <iostream>

using namespace std;

int main()
{
    int x, y, a;;
    cin >> x >> y;
    string b[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    if (x > 11) a = 31 * (x - 1) - 7 + y;
    else if (x > 9) a = 31 * (x - 1) - 6 + y;
    else if (x > 6) a = 31 * (x - 1) - 5 + y;
    else if (x > 4) a = 31 * (x - 1) - 4 + y;
    else if (x > 2) a = 31 * (x - 1) - 3 + y;
    else a = 31 * (x - 1) + y;
    cout << b[(a - 1) % 7];
}

