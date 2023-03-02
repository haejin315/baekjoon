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

long long b[8000001] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a[31] = {0}, b[55001] = {0}, N, M, check, c;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    b[40000] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = a[i]; j < 55001; j++) {
            if (b[j] == 0)continue;
            b[j - a[i]] = 1;
        }
        for (int j = 55001 - a[i]; j >= 0; j--) {
            if (b[j] == 0)continue;
            b[j + a[i]] = 1;
        }
    }

    for (int i = 0; i < 55001; i++) {
        if (b[i] == 1)cout << i - 40000 << endl;
    }


    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> check;
        if (check > 15001)cout << "N ";
        else if (b[check + 40000] == 1)cout << "Y ";
        else cout << "N ";
    }



}

