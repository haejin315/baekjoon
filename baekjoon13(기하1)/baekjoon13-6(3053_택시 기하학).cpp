#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a;
    double pi = acos(-1);
    cin >> a;
    cout << fixed;
    cout.precision(6);
    cout << a * a * pi << "\n" << 2 * a * a << "\n";
}
