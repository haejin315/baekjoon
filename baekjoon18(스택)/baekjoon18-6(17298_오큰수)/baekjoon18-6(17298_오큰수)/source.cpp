
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int t[1000001][2] = { 0 };
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    stack<int> a;
    for (int i = 0; i < N; i++) {
        cin >> t[i][0];
    }
    for (int i = 0; i < N; i++) {
        if (a.size() == 0) {
            a.push(i);
        }
        else {
            while (1) {
                if (a.size() == 0)break;
                if (t[a.top()][0] >= t[i][0])break;
                else if (t[a.top()][0] < t[i][0]) {
                    t[a.top()][1] = t[i][0];
                    a.pop();
                }
            }
            a.push(i);
        }
    }
    for (int i = 0; i < N; i++) {
        if (t[i][1] == 0)t[i][1]--;
        cout << t[i][1] << " ";
    }
}

