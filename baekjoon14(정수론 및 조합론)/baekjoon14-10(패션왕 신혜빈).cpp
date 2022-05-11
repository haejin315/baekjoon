
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[31][31];

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n, m;
    string a;
    cin >> m;
    for (int k = 0; k < m; k++) {
        vector<string> b;
        vector<int> c;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> a;
            if (i == 0) {
                b.push_back(a);
                c.push_back(1);
                continue;
            }
            for (int j = 0; j < b.size(); j++) {
                if (b[j] == a) {
                    c[j]++;
                    break;
                }
                else if (j == b.size() - 1) {
                    b.push_back(a);
                    c.push_back(1);
                    break;
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i <= c.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                }
                else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] * c[i - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] * c[i - 1] + dp[i - 1][j];
                }
            }
        }
        for (int i = 1; i <= c.size(); i++) {
            ans += dp[c.size()][i];
        }
        cout << ans << "\n";
    }
}

