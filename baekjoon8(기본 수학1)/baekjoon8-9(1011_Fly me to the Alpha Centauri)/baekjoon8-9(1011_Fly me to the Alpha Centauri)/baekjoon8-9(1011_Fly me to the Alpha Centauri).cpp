// baekjoon8-9(1011_Fly me to the Alpha Centauri).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int c;
    cin >> c;
    for (int k = 0; k < c; k++) {
        long long a, b;
        cin >> a >> b;
        long long i = 256;
        long long e = 0;
        long long d = 65536;
        long long s = b - a;
        if (s == 0) { cout << 1 << "\n"; continue; }
        while (1) {
            if (i * (i + 1) > s) {
                if (i - e == 1) { 
                    if (s - e * i < e + 2) {
                        cout << e * 2 + 1 << "\n";
                    }
                    else {
                        cout << e * 2 + 2 << "\n";
                    }
                    break; 
                }
                d = i;
                i = (e + i - ((e + i) % 2)) / 2;
                continue;
            }
            if (i * (i + 1) < s) {
                if (d - i == 1) {
                    if (s - i * d < i + 2) {
                        cout << i * 2 + 1 << "\n";
                    }
                    else {
                        cout << i * 2 + 2 << "\n";
                    }
                    break;
                }
                e = i;
                i = (d + i + ((d + i) % 2)) / 2;
                continue;
            }
            if (i * (i + 1) == s) {
                cout << i * 2 << "\n";
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
