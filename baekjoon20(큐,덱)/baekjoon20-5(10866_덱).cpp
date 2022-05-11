
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    deque<int> a;
    int N, c;
    string b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b == "push_front") {
            cin >> c;
            a.push_front(c);
        }
        else if (b == "push_back") {
            cin >> c;
            a.push_back(c);
        }
        else if (b == "pop_front") {
            if (a.size() == 0)cout << "-1\n";
            else {
                cout << a.front() << "\n";
                a.pop_front();
            }
        }
        else if (b == "pop_back") {
            if (a.size() == 0)cout << "-1\n";
            else {
                cout << a.back() << "\n";
                a.pop_back();
            }
        }
        else if (b == "size") {
            cout << a.size() << "\n";
        }
        else if (b == "empty") {
            if (a.size() == 0)cout << "1\n";
            else cout << "0\n";
        }
        else if (b == "front") {
            if (a.size() != 0)cout << a.front() << "\n";
            else cout << "-1\n";
        }
        else if (b == "back") {
            if (a.size() != 0)cout << a.back() << "\n";
            else cout << "-1\n";
        }
    }
}

