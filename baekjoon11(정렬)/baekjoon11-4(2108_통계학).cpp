
#include <iostream>
#include <math.h>

using namespace std;

int a[8001] = { 0 };

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, m;
    double sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> m;
        a[m + 4000]++;
        sum += m;
    }
    int mid = 0;
    for (int i = 0; i < 8001; i++) {
        if (a[i] == 0)continue;
        mid += a[i];
        if (mid >= N / 2 + 1) {
            mid = i;
            break;
        }
    }
    int man = 0;
    int min = -1;
    int max = 0;
    int check = 0;
    for (int i = 0; i < 8001; i++) {
        if (a[i] == 0)continue;
        if (a[i] == a[man]) {
            if (i == 0) {
                check = 1;
            }
            else if (check == 1) {
                check = 2;
                man = i;
            }
        }
        else if (a[i] > a[man]) {
            man = i;
            check = 1;
        }
        if (min == -1)min = i;
        max = i;
        
    }
    cout << floor(sum / N + 0.5) << "\n" << mid - 4000 << "\n" << man - 4000 << "\n" << max - min;
}
