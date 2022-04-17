
#include <iostream>

using namespace std;

constexpr int mod = 1000;
int N;
long long B;
int m[25];
int* a1 = new int[25]{ 0 };
int* a2 = new int[25]{ 0 };
int* b = new int[25]{ 0 };
int m2[1000000][25] = { 0 };

int* matdot(int m1[25], int m2[25], long long count) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            b[i * 5 + j] = 0;
            for (int k = 0; k < N; k++) {
                b[i * 5 + j] += (m1[i * 5 + k] * m2[k * 5 + j]) % mod;
            }
            if (count == B) {
                cout << b[i * 5 + j] % mod << " ";
            }
        }
        if(count == B)
        cout << "\n";
    }
    return b;
}

int* powmat(long long count){
    if (count == 1) return m;
    int a11[25];
    if (count < 2000000 && m2[count / 2][0] != 0) {
        for (int i = 0; i < 25; i++) {
            a11[i] = m2[count / 2][i];
        }
    }
    else {
        a1 = powmat(count / 2);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                a11[i * 5 + j] = a1[i * 5 + j];
            }
        }
    }
    if (count % 2 == 0) {
        return matdot(a11, a11, count);
    }
    else {
        int a22[25];
        if (count < 2000000 && m2[(count / 2) + 1][0] != 0) {
            for (int i = 0; i < 25; i++) {
                a22[i] = m2[(count / 2) + 1][i];
            }
        }
        else {
            a2 = matdot(a11, m, 0);
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    a22[i * 5 + j] = a2[i * 5 + j];
                }
            }
        }
        return matdot(a11, a22, count);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i*5+j];
        }
    }
    if (B == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << m[i * 5 + j] % mod << " ";
            }
            cout << "\n";
        }
    }
    powmat(B);
}

