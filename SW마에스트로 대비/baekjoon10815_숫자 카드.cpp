#include <iostream>
#include <map>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    map<int, int> a;
    
    int b, c;
    cin >> b;
    for (int i = 0; i < b; i++) {
        cin >> c;
        a.insert({ c, 1 });
    }
    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> b;
        cout << a[b] << " ";
    }

}

