
#include <iostream>
#include <string>

using namespace std;

int Count[200010][26] = { 0 };

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string arr;
    int q, begin, end;
    char target;
    cin >> arr >> q;
    Count[1][arr[0] - 97]++;
    for (int i = 1; i < arr.length(); i++) {
        for (int j = 0; j < 26; j++) {
            Count[i + 1][j] = Count[i][j];
        }
        Count[i + 1][arr[i] - 97] = Count[i][arr[i] - 97] + 1;
    }

    for (int i = 0; i < q; i++) {
        cin >> target >> begin >> end;
        cout << Count[end + 1][target - 97] - Count[begin][target - 97] << "\n";
    }

}

