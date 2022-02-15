
#include <iostream>

using namespace std;

class z {
public:
    long long a = 0;
    z* left = NULL;
    z* right = NULL;
    z* sort(z* a, int b) {
        z* c = a;
        z* d = a;
        for (int i = 0; i < b / 2; i++) {
            d = d->right;
        }
        if (b == 1) {
            return a;
        }
        if (b == 2) {
            if (c->a <= d->a) { return a; }
            else {
                c->left = d;
                d->right = c;
                c->right = NULL;
                d->left = NULL;
                return d;
            }
        }
        d->left->right = NULL;
        d->left = NULL;
        c = sort(c, b / 2);
        d = sort(d, b - b / 2);
        int e = 1;
        z* start = NULL;
        z* cur = new z();
        z* ne;
        if (c->a > d->a) {
            cur->a = d->a;
            d = d->right;
        }
        else {
            cur->a = c->a;
            c = c->right;
        }
        start = cur;
        while (1) {
            e++;
            if (c == NULL && d == NULL)break;
            ne = new z();
            cur->right = ne;
            ne->left = cur;
            if (c == NULL) {
                ne->a = d->a;
                d = d->right;
                cur = ne;
            }
            else if (d == NULL) {
                ne->a = c->a;
                c = c->right;
                cur = ne;
            }
            else {
                if (c->a > d->a) {
                    ne->a = d->a;
                    cur = ne;
                    d = d->right;
                }
                else {
                    ne->a = c->a;
                    cur = ne;
                    c = c->right;
                }
            }
        }
        return start;
    }
};
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    if (N == 1) { cout << "Yes"; return 0; }
    z* start = new z();
    cin >> start->a;
    z* cur = start;
    for (int i = 1; i < N; i++) {
        z* input = new z();
        cin >> input->a;
        cur->right = input;
        input->left = cur;
        cur = input;
    }
    long long da = start->a;
    start = start->sort(start, N);
    long long ans = da;
    while (1) {
        if (da == start->a) {
            da = 0;
        }
        else if (ans < start->a) {
            cout << "No";
            return 0;
        }
        else if (ans > start->a) {
            ans += start->a;
        }
        if (start->right == NULL)break;
        start = start->right;
    }
    if (ans == start->a) {
        cout << "No";
        return 0;
    }
    cout << "Yes";
}
