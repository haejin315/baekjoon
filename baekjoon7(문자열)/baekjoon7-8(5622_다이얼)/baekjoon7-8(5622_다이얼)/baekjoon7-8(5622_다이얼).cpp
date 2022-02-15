﻿// baekjoon7-8(5622_다이얼).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int second(char b) {
    if (b == 'A' || b == 'B' || b == 'C') { return 3; }
    if (b == 'D' || b == 'E' || b == 'F') { return 4; }
    if (b == 'G' || b == 'H' || b == 'I') { return 5; }
    if (b == 'J' || b == 'K' || b == 'L') { return 6; }
    if (b == 'M' || b == 'N' || b == 'O') { return 7; }
    if (b == 'P' || b == 'Q' || b == 'R' || b == 'S') { return 8; }
    if (b == 'T' || b == 'U' || b == 'V') { return 9; }
    if (b == 'W' || b == 'X' || b == 'Y' || b == 'Z') { return 10; }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    string a;
    cin >> a;
    int b = 0;
    for (int i = 0; i < a.size(); i++) {
        b += second(a[i]);
    }
    cout << b;
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
