// baekjoon(20057_마법사 상어와 토네이도).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int a[511][511] = { 0 };
int way = 1;

void to(int a1, int a2) {
    if (abs(way) == 1) {
        a[a1][a2 - way] += a[a1][a2] * 7 / 100;
        a[a1][a2 + way] += a[a1][a2] * 7 / 100;
        a[a1 - way][a2 - way] += a[a1][a2] * 10 / 100;
        a[a1 - way][a2 + way] += a[a1][a2] * 10 / 100;
        a[a1 + way][a2 - way] += a[a1][a2] * 1 / 100;
        a[a1 + way][a2 + way] += a[a1][a2] * 1 / 100;
        a[a1][a2 - 2 * way] += a[a1][a2] * 2 / 100;
        a[a1][a2 + 2 * way] += a[a1][a2] * 2 / 100;
        a[a1 - 2 * way][a2] += a[a1][a2] * 5 / 100;
        a[a1 - 1 * way][a2] += a[a1][a2] - (a[a1][a2] * 7 / 100 + a[a1][a2] * 7 / 100
            + a[a1][a2] * 10 / 100 + a[a1][a2] * 10 / 100
            + a[a1][a2] * 1 / 100 + a[a1][a2] * 1 / 100
            + a[a1][a2] * 2 / 100 + a[a1][a2] * 2 / 100
            + a[a1][a2] * 5 / 100);
        a[a1][a2] = 0;
    }
    else {
        way /= -2;
        a[a1 - way][a2] += a[a1][a2] * 7 / 100;
        a[a1 + way][a2] += a[a1][a2] * 7 / 100;
        a[a1 - way][a2 - way] += a[a1][a2] * 10 / 100;
        a[a1 + way][a2 - way] += a[a1][a2] * 10 / 100;
        a[a1 - way][a2 + way] += a[a1][a2] * 1 / 100;
        a[a1 + way][a2 + way] += a[a1][a2] * 1 / 100;
        a[a1 - 2 * way][a2] += a[a1][a2] * 2 / 100;
        a[a1 + 2 * way][a2] += a[a1][a2] * 2 / 100;
        a[a1][a2 - 2 * way] += a[a1][a2] * 5 / 100;
        a[a1][a2 - 1 * way] += a[a1][a2] - (a[a1][a2] * 7 / 100 + a[a1][a2] * 7 / 100
            + a[a1][a2] * 10 / 100 + a[a1][a2] * 10 / 100
            + a[a1][a2] * 1 / 100 + a[a1][a2] * 1 / 100
            + a[a1][a2] * 2 / 100 + a[a1][a2] * 2 / 100
            + a[a1][a2] * 5 / 100);
        a[a1][a2] = 0;
        way *= -2;
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    int a1 = N / 2 + 2;
    int a2 = a1;
    int start = 1;
    int end = 0;
    for (int i = 2; i <= N + 1; i++) {
        for (int j = 2; j <= N + 1; j++) {
            cin >> a[j][i];
        }
    }
    while (1) {
        if (start % 2 == 1) {
            for (int i = 1; i <= start; i++) {
                if (i == start && a2 == 2) { end = 1; break; }
                a1 -= 1;
                to(a1, a2);
            }
            way = 2;
            if (end == 1)break;
            for (int i = 1; i <= start; i++) {
                a2 += 1;
                to(a1, a2);
            }
            way = -1;
        }
        else {
            for (int i = 1; i <= start; i++) {
                a1 += 1;
                to(a1, a2);
            }
            way = -2;
            for (int i = 1; i <= start; i++) {
                a2 -= 1;
                to(a1, a2);
            }
            way = 1;
        }
        start++;
    }
    int sum = 0;
    for (int i = 0; i < N + 4; i++) {
        for (int j = 0; j < N + 4; j++) {
            if (!(i > 1 && i < N + 2 && j > 1 && j < N + 2)) {
                sum += a[i][j];
            }
        }
    }
    cout << sum;
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
