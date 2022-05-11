#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    double x1, y1, r1, x2, y2, r2;
    int a;
    cin >> a;
    while (1){
        if (a == 0)break;
        int big;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if (x1 == x2 && y1 == y2 && r1 == r2) { cout << "-1\n"; a--; continue; }
        if (r1 >= r2)big = r1;
        else big = r2;
        double dis = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        if (dis > big) {
            if (dis > r1 + r2)cout << "0\n";
            else if (dis == r1 + r2)cout << "1\n";
            else cout << "2\n";
        }
        else if (dis < big) {
            if (dis < abs(r1 - r2))cout << "0\n";
            else if (dis == abs(r1 - r2))cout << "1\n";
            else cout << "2\n";
        }
        else {
            cout << "2\n";
        }
        a--;
    }
}