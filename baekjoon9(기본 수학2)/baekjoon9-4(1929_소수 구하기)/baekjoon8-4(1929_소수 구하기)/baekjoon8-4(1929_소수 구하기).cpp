// baekjoon8-4(1929_소수 구하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

using namespace std;

int a[1000001] = { 0 };
int aa[1000001] = { 0 };

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int g = 3;
    int h = 10;
    n = g;
    m = h;
    while (1) {
        int k = 3;
        while (k <= m / 2) {
            for (int i = k; i <= m; i += k * 2) {
                a[i] = 1;
            }
            for (int i = k; i <= m / 2; i += 2) {
                if (a[i] == 0) {
                    a[k] = 0;
                    k = i;
                    break;
                }
                if (i == m / 2 || i == m / 2 - 1) {
                    a[k] = 0;
                    k = m;
                }
            }
        }

        if (n <= 2) {
            cout << 2 << "\n";

        }
        if (n == 1) {
            n += 2;
        }
        /*
        for (int j = n; j < m + 1; j += 2) {
            if (n % 2 == 0) { j++; n++; }
            if (a[j] == 0) {
                cout << j << "\n";

            }
        }
        */
        if (n <= 2) {
            cout << 2 << "\n";

        }
        if (n % 2 == 0) {
            n++;
        }
        if (n == 1) {
            n = 3;
        }

        for (int i = 3; i <= m; i += 2) {
            if (aa[i] == 1)continue;
            for (int j = i + i; j <= m; j += i) {
                aa[j] = 1;
            }
        }


        for (int j = n; j <= m; j += 2) {
            if (a[j] == 0) {
                if (a[j] != aa[j]) {
                    cout << g << " " << h << " " << j << "\n";
                }
            }
        }
        g++;
        if (g == m) {
            g = 3;
            m++;
            cout << g << " " << m << "\n";
            if (m == 20000) {
                break;
            }
        }
    }
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
