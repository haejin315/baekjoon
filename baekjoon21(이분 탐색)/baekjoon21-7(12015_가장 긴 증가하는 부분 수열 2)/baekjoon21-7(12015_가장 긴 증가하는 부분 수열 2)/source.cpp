
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void fc(int b) {
    int begin = 1, end = a.size() - 1, ans;
    while (1) {
        if (begin > end)break;
        int mid = (begin + end) / 2;
        if (b > a[mid]) {
            ans = mid;
            begin = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    a[ans + 1] = b;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, b;
    cin >> N;

    a.push_back(-1);
    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b > a.back()) {
            a.push_back(b);
        }
        else {
            if (b <= a[1])a[1] = b;
            else {
                fc(b);
            }
        }
    }
    cout << a.size() - 1;
}

