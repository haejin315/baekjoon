#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, a, c, d, e, f = INT16_MAX;
    long long s = 0;
    stack<int> b;
    
    cin >> N >> a;
    b.push(a);
    for (int i = 1; i < N; i++) {
        cin >> a;

        d = 1;
        c = b.top();
        e = b.size();

        if (b.top() >= a) {
            b.push(a);
        }
        else {

            while (b.top() < a) {

                s++;
                c = b.top();
                b.pop();

                if (b.empty()) {
                    s--;
                    break;
                }

                if (c == b.top()) {
                    d++;
                }
                else {
                    //s += d;
                    for (int j = 1; j < d; j++) {
                        s += j;
                    }
                    d = 1;
                }

            }
            //if (!b.empty())s++;
            s += e - b.size();
            b.push(a);
        }
    }


    d = 0;
    while (b.size() > 1) {

        s++;
        c = b.top();
        b.pop();
        if (c == b.top()) {
            d++;
        }
        else {
            for (int j = 1; j <= d; j++) {
                s += j;
            }
            d = 0;
        }
    }

    if (d != 0) {
        for (int i = 1; i < d; i++) {
            s += i;
        }
    }

    cout << s;
}

