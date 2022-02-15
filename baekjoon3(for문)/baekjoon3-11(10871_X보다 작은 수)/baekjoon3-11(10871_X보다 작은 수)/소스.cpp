#include <iostream>

int main()
{
    int N, X;
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    std::cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        int A;
        std::cin >> A;
        if (A < X) { std::cout << A << " "; }
    }
}