
#include <iostream>
#include <deque>
#include <string>

using namespace std;

string arrint[100010] = {};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int T, arrlen, cur, pre, front, back, reverse, flen, arrlen2;
    string f, arr;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> f >> arrlen >> arr;
        flen = f.length();
        arrlen2 = arr.length();
        cur = 0;
        pre = 1;
        if (arrlen > 0 ) {
            for (int j = 1; j < arrlen2; j++) {
                if (arr[j] == ',') {
                    arrint[cur] = arr.substr(pre, j - pre);
                    pre = j + 1;
                    cur++;
                }
            }
            arrint[cur] = arr.substr(pre, arrlen2 - pre - 1);
        }
        front = 0;
        back = cur;
        reverse = 1;
        for (int j = 0; j < flen; j++) {
            if (f[j] == 'D') {
                if (back < front || arrlen == 0) {
                    pre = -10;
                    break;
                }
                else if (reverse == 1) {
                    front++;
                }
                else {
                    back--;
                }
            }
            else {
                reverse *= -1;
            }
        }
        if (pre == -10) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if (arrlen != 0) {
                if (reverse == 1) {
                    for (int j = front; j < back; j++) {
                        cout << arrint[j] << ",";
                    }
                    if (back >= front) {
                        cout << arrint[back];
                    }
                }
                else {
                    for (int j = back; j > front; j--) {
                        cout << arrint[j] << ",";
                    }
                    if (back >= front) {
                        cout << arrint[front];
                    }
                }
            }
            cout << "]\n";
        }
    }
}

