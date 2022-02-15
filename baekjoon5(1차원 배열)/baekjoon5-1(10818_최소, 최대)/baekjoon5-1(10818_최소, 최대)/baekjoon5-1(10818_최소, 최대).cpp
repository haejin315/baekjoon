#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int* A = new int[N];
    int S = 1000001;
    int B = -1000001;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > B) { B = A[i]; }
        if (A[i] < S) { S = A[i]; }
    }
    cout << S << " " << B;
}