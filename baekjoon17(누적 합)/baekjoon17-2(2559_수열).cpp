
#include <iostream>

using namespace std;

int arr[100100][2];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N, K, big = INT32_MIN, sum;
    cin >> N >> K;
    arr[0][1] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0];
        arr[i][1] = arr[i - 1][1] + arr[i][0];
    }
    for (int i = K; i <= N; i++) {
        sum = arr[i][1] - arr[i - K][1];
        if (big < sum)big = sum;
    }
    cout << big;
}

