
#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    vector<int> a;
    int N, b, c;
    int d = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    for (int i = a[1] - a[0]; i > 1; i--) {
        c = a[0] % i;
        for (int j = 1; j < a.size(); j++) {
            if (a[j] % i != c) {
                d = 0;
                break;
            }
        }
        if (d == 1) {
            d = i;
            break;
        }
        d = 1;
    }
    vector<int> aa;
    for (int i = 2; i <= sqrt(d); i++) {
        if (d % i == 0) {
            cout << i << " ";
            aa.push_back(i);
        }
    }
    cout << aa.size();
    for (int i = aa.size() - 1; i >= 0; i++) {
        cout << d / aa[i] << " ";
    }
    cout << d;
}

