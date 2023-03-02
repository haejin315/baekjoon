#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int c[1000001] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> a, aa;
    int N, b;
    cin >> N;
    a.push_back(INT32_MIN);
    for (int i = 1; i <= N; i++) {
        cin >> b;
        aa.push_back(b);
        if (b > a.back()) {
            a.push_back(b);
            c[i] = a.size() - 1;
        }
        else {
            int lb = lower_bound(a.begin(), a.end(), b) - a.begin();
            a[lb] = b;
            c[i] = lb;
        }
    }

    //for (int i = N; i >= 1; i--) {
    //    cout << c[i] << " ";
    //}
    //cout << endl;

    int k = a.size() - 1;
    cout << k << "\n";
    vector<int> d;
    for (int i = N; i >= 1; i--) {
        if (c[i] == k) {
            d.push_back(aa[i - 1]);
            k--;
        }
        if (k == 0)break;
    }
    for (int i = d.size() - 1; i >= 0; i--) {
        cout << d[i] << " ";
    }
}

