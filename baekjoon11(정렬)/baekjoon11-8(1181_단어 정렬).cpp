#include <iostream>

using namespace std;

string word[20001];
string test[20001];

void merge(int a, int b) {
    int c = (a + b) / 2;
    if (b - a == 1) {
        return;
    }
    if (b - a == 2) {
        if (word[a].length() < word[c].length()) {
            return;
        }
        else if (word[a].length() > word[c].length()) {
            string w = word[a];
            word[a] = word[c];
            word[c] = w;
            return;
        }
        else {
            int len = 0;
            while (len != word[a].length()) {
                if (word[a][len] < word[c][len]) {
                    return;
                }
                else if (word[a][len] > word[c][len]) {
                    string w = word[a];
                    word[a] = word[c];
                    word[c] = w;
                    return;
                }
                len++;
            }
            return;
        }
    }
    merge(a, c);
    merge(c, b);
    int start = a;
    int middle = c;
    for (int i = 0; i < b - start; i++) {
        if (a == middle) {
            test[i] = word[c];
            c++;
        }
        else if (c == b) {
            test[i] = word[a];
            a++;
        }
        else if (word[a] == word[c]) {
            test[i] = word[a];
            a++;
        }
        else {
            if (word[a].length() < word[c].length()) {
                test[i] = word[a];
                a++;
            }
            else if (word[a].length() > word[c].length()) {
                test[i] = word[c];
                c++;
            }
            else {
                int len = 0;
                while (len != word[a].length()) {
                    if (word[a][len] < word[c][len]) {
                        test[i] = word[a];
                        a++;
                        break;
                    }
                    else if (word[a][len] > word[c][len]) {
                        test[i] = word[c];
                        c++;
                        break;
                    }
                    len++;
                }
            }
        }
    }
    for (int i = 0; i < b - start; i++) {
        word[i + start] = test[i];
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> word[i];
    }
    merge(0, N);
    cout << word[0] << "\n";
    for (int i = 1; i < N; i++) {
        if (word[i - 1] != word[i]) {
            cout << word[i] << "\n";
        }
    }
}
