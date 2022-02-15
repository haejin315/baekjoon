// baekjoon11-4(1018_체스판 다시 칠하기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    string* a = new string[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int bb = 3000;
    int cc = 3000;
    for (int k = 0; k <= N - 8; k++) {
        for (int s = 0; s <= M - 8; s++) {
            int b = 0;
            int c = 0;
            for (int i = k; i < k + 8; i++) {
                for (int j = s; j < s + 8; j++) {
                    if ((i + j) % 2 == 0 && a[i][j] == 'W')b++;
                    else if ((i + j) % 2 == 1 && a[i][j] == 'B')b++;
                    if ((i + j) % 2 == 0 && a[i][j] == 'B')c++;
                    else if ((i + j) % 2 == 1 && a[i][j] == 'W')c++;
                }
            }
            if (b < bb)bb = b;
            if (c < cc)cc = c;
        }
    }
    if (bb >= cc)cout << cc;
    else cout << bb;
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
