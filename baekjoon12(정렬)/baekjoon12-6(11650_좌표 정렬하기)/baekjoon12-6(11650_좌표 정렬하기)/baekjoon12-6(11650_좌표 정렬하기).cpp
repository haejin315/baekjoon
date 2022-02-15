
#include <iostream>

using namespace std;

int** x;

void merge(int a, int b, int xy) {
    int c = (a + b) / 2;
    if(b - a == 1){
        return;
    }
    if (b - a == 2) {
        if (x[a][xy] <= x[c][xy]) {
            return;
        }
        else {
            x[a][xy] ^= x[c][xy];
            x[c][xy] ^= x[a][xy];
            x[a][xy] ^= x[c][xy];
            x[a][(xy + 1) % 2] ^= x[c][(xy + 1) % 2];
            x[c][(xy + 1) % 2] ^= x[a][(xy + 1) % 2];
            x[a][(xy + 1) % 2] ^= x[c][(xy + 1) % 2];
            return;
        }
    }
    merge(a, c, xy);
    merge(c, b, xy);
    int start = a;
    int middle = c;
    int** co = new int*[b - a];
    for (int i = 0; i < b - start; i++) {
        co[i] = new int[2];
        if (a == middle) {
            co[i][xy] = x[c][xy];
            co[i][(xy + 1) % 2] = x[c][(xy + 1) % 2];
            c++;
        }
        else if (c == b) {
            co[i][xy] = x[a][xy];
            co[i][(xy + 1) % 2] = x[a][(xy + 1) % 2];
            a++;
        }
        else {
            if (x[a][xy] <= x[c][xy]) {
                co[i][xy] = x[a][xy];
                co[i][(xy + 1) % 2] = x[a][(xy + 1) % 2];
                a++;
            }
            else {
                co[i][xy] = x[c][xy];
                co[i][(xy + 1) % 2] = x[c][(xy + 1) % 2];
                c++;
            }
        }
    }
    for (int i = 0; i < b - start; i++) {
        x[i + start][xy] = co[i][xy];
        x[i + start][(xy + 1) % 2] = co[i][(xy + 1) % 2];
    }
    for (int i = 0; i < b - start - 1; i++) {
        delete co[i];
    }
    delete co;
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    x = new int* [N];
    for (int i = 0; i < N; i++) {
        x[i] = new int[2];
        cin >> x[i][0] >> x[i][1];
    }
    
    merge(0, N, 1);
    merge(0, N, 0);
    for (int i = 0; i < N; i++) {
        cout << x[i][0] << " " << x[i][1] << "\n";
    }
}
